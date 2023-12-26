/**
 * @file Application.h
 * @author DWI
 * @date 2021-12-12
 */
#ifndef CIRCUIT_SIM_APPLICATION
#define CIRCUIT_SIM_APPLICATION

#include <cstdint>
#include <map>
#include <unordered_map>

namespace circuitsim
{
namespace application
{

enum class CmdLineParams
{
    NUM_OF_ITERATIONS,
    PRINTABLE_ITERATIONS,
    TIME_STEP,
    BATTERY_VOLTAGE
};

const std::map<CmdLineParams, std::string> CmdLineParamsNames{
    {CmdLineParams::NUM_OF_ITERATIONS, "Number of iterations"},
    {CmdLineParams::PRINTABLE_ITERATIONS, "Printable iterations"},
    {CmdLineParams::TIME_STEP, "Time step"},
    {CmdLineParams::BATTERY_VOLTAGE, "Battery voltage"},
};

struct EnumClassHash
{
    template <typename T>
    std::size_t operator()(T t) const
    {
        return static_cast<std::size_t>(t);
    }
};

using cmdline_t = std::unordered_map<CmdLineParams, double, EnumClassHash>;

class Application
{

  public:
    Application();
    Application(double num_of_iterations, double printable_iterations, double time_step, double battery_voltage);
    std::int32_t RunSimulation(const std::int32_t argc, char* argv[]);

  private:  // methods
    bool ParseCmdLineArgs(const std::int32_t argc, char* argv[]);
    void PrintUsage(void) const;
    bool ValidateArgs() const;
    void PrintAllCmdLineParams() const;

  private:  // members
    cmdline_t cmd_params_;
};

// Free functions

}  // namespace application
}  // namespace circuitsim

#endif  // CIRCUIT_SIM_APPLICATION