/**
 * @file Parameters.hpp
 * @brief Definition of the basic paramters for each component
 *
 * @author DWI
 */
#ifndef CIRCUIT_SIM_PARAMETERS
#define CIRCUIT_SIM_PARAMETERS

#include <cstdint>
#include <string>
#include <unordered_map>

namespace circuitsim
{
namespace components
{

enum class ElectricComponent : std::uint8_t
{
    Battery = 0U,
    Resistor = 1U,
    // Add new components here.
};

enum class ParameterType : std::uint32_t
{
    Resistance = 0U,
    Voltage = 1U,
    InternalResistance = 2U,
    // Add new parameter types here.
};

struct ComponentData
{
    ElectricComponent type;
    std::string name;
    std::string p_terminal;
    std::string n_terminal;
    std::unordered_map<ParameterType, double> parameters;
};

}  // namespace components
}  // namespace circuitsim

#endif  // CIRCUIT_SIM_PARAMETERSs