/**
 * @file Battery.cpp
 *
 * @author DWI
 * @date 2021-12-12
 */

#include <iomanip>
#include <iostream>
#include <vector>

#include "Circuit.hpp"
#include "Simulate.hpp"

namespace circuitsim
{
namespace application
{

int32_t Simulate::Run(const std::uint32_t& num_of_iterations,
                      const std::uint32_t& iterations_printable,
                      const double& iteration_time_step)
{
    if (circuit_ == nullptr)
    {
        return EXIT_FAILURE;
    }

    const auto resolve_result = circuit_->Resolve();
    if (resolve_result == EXIT_FAILURE)
    {
        return EXIT_FAILURE;
    }

    PrintComponentHeader(circuit_->GetComponentsNames());

    ComponentsParamMap components_params{};
    const uint32_t printable = num_of_iterations / iterations_printable;

    for (uint32_t i = 0; i < num_of_iterations; ++i)
    {
        circuit_->GetComponentsParameters(iteration_time_step, components_params);

        if (i % printable == 0)
        {
            PrintComponentData(components_params);
        }
    }

    return EXIT_SUCCESS;
}

void Simulate::PrintComponentHeader(const std::vector<std::string>& data)
{
    for ([[maybe_unused]] const auto& entry : data)
    {
        std::cout << std::setw(10) << std::setfill(' ') << entry << "|";
    }
    std::cout << std::endl;

    for ([[maybe_unused]] const auto& entry : data)
    {
        std::cout << std::setw(5) << std::setfill(' ') << "Volt" << std::setw(5) << "Curr"
                  << "|";
    }
    std::cout << std::endl;
}

void Simulate::PrintComponentData(const ComponentsParamMap& data)
{
    for (const auto& entry : data)
    {
        std::cout << std::fixed << std::setprecision(2) << std::setw(5) << entry.second.first << " "  // Voltage
                  << std::setw(2) << entry.second.second << " "                                       // Current
                  << std::setw(2) << std::setfill(' ');
    }
    std::cout << std::endl;
}

}  // namespace application
}  // namespace circuitsim
