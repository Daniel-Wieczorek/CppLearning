/**
 * @file Application.cpp
 *
 * @author DWI
 * @date 2021-12-12
 */

#include "Application.hpp"
#include "Circuit.hpp"
#include "Simulate.hpp"

#include <unistd.h>
#include <iostream>
#include <memory>
#include <string>

namespace circuitsim
{
namespace application
{

Application::Application() : Application(0.0, 0.0, 0.0, 0.0){};

Application::Application(const double num_of_iterations,
                         const double printable_iterations,
                         const double time_step,
                         const double battery_voltage)
{
    cmd_params_[CmdLineParams::NUM_OF_ITERATIONS] = num_of_iterations;
    cmd_params_[CmdLineParams::PRINTABLE_ITERATIONS] = printable_iterations;
    cmd_params_[CmdLineParams::TIME_STEP] = time_step;
    cmd_params_[CmdLineParams::BATTERY_VOLTAGE] = battery_voltage;
}

std::int32_t Application::RunSimulation(const std::int32_t argc, char* argv[])
{
    if (!ParseCmdLineArgs(argc, argv) || !ValidateArgs())
    {
        std::cerr << "Invalid cmdline arguments, see usage:\n";
        PrintUsage();
        return EXIT_FAILURE;
    }

    PrintAllCmdLineParams();

    // Declare all components:
    circuitsim::components::ComponentData Resistor1;
    Resistor1.type = circuitsim::components::ElectricComponent::Resistor;
    Resistor1.name = "R1";
    Resistor1.p_terminal = "p";
    Resistor1.n_terminal = "a";
    Resistor1.parameters = {{circuitsim::components::ParameterType::Resistance, 5}};

    circuitsim::components::ComponentData Resistor2;
    Resistor2.type = circuitsim::components::ElectricComponent::Resistor;
    Resistor2.name = "R2";
    Resistor2.p_terminal = "a";
    Resistor2.n_terminal = "n";
    Resistor2.parameters = {{circuitsim::components::ParameterType::Resistance, 5}};

    circuitsim::components::ComponentData Battery;
    Battery.type = circuitsim::components::ElectricComponent::Battery;
    Battery.name = "Bat1";
    Battery.p_terminal = "p";
    Battery.n_terminal = "n";
    Battery.parameters = {
        {circuitsim::components::ParameterType::Voltage, cmd_params_[CmdLineParams::BATTERY_VOLTAGE]}};

    auto circuit = std::make_unique<Circuit>();

    if (!circuit)
    {
        std::cerr << "Failed to create circuit\n";
        return EXIT_FAILURE;
    }

    circuit->AddComponent(Resistor1);
    circuit->AddComponent(Resistor2);
    circuit->AddComponent(Battery);

    auto simulator = std::make_unique<Simulate>(circuit);
    if (!simulator)
    {
        std::cerr << "Failed to create simulator\n";
        return EXIT_FAILURE;
    }

    simulator->Run(cmd_params_[CmdLineParams::NUM_OF_ITERATIONS],
                   cmd_params_[CmdLineParams::PRINTABLE_ITERATIONS],
                   cmd_params_[CmdLineParams::TIME_STEP]);

    return EXIT_SUCCESS;
}

bool Application::ParseCmdLineArgs(const std::int32_t argc, char* argv[])
{
    int32_t c{0};
    while ((c = getopt(argc, argv, "i:p:t:u:")) != -1)
    {
        switch (c)
        {
            case 'i':
                cmd_params_.at(CmdLineParams::NUM_OF_ITERATIONS) = std::atoi(optarg);
                break;
            case 'p':
                cmd_params_.at(CmdLineParams::PRINTABLE_ITERATIONS) = std::atoi(optarg);
                break;
            case 't':
                cmd_params_.at(CmdLineParams::TIME_STEP) = std::atof(optarg);
                break;
            case 'u':
                cmd_params_.at(CmdLineParams::BATTERY_VOLTAGE) = std::atoi(optarg);
                break;
            case '?':
                std::cerr << "Invalid argument passed, see usage:\n";
                PrintUsage();
                return false;
            default:
                std::cerr << "Invalid argument passed, see usage:\n";
                PrintUsage();
                return false;
        }
    }
    return true;
}

void Application::PrintAllCmdLineParams() const
{
    std::cout << "Passed cmd line args:\n";
    auto print_key_value = [](const CmdLineParams& key, const double& value) {
        std::cout << CmdLineParamsNames.at(key) << ": " << value << "\n";
    };

    for (const auto& [key, value] : cmd_params_)
    {
        print_key_value(key, value);
    }
}

bool Application::ValidateArgs() const
{
    for (const auto& [key, value] : cmd_params_)
    {
        if (value <= 0)
        {
            return false;
        }
    }
    return true;
}

void Application::PrintUsage(void) const
{
    std::cerr << "   voltage_simulator -i iterations -p printable_iterations -t time step -u battery voltage\n";
    std::cerr << "      -i: the number of iterations to simulate\n";
    std::cerr << "      -p: how many iterations (lines) to print\n";
    std::cerr << "      -t: the time step used in each iteration\n";
    std::cerr << "      -u: the battery voltage\n";
}

}  // namespace application
}  // namespace circuitsim
