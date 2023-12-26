/**
 * @file Parameters.hpp
 * @brief This file defines the basic parameters for each component in the circuit simulation.
 *
 * @author DWI
 */
#ifndef CIRCUIT_SIM_SRC_COMPONENTS_PARAMETERS
#define CIRCUIT_SIM_SRC_COMPONENTS_PARAMETERS

#include <cstdint>
#include <string>
#include <unordered_map>

namespace circuitsim
{
namespace components
{

enum class ElectricComponent : std::uint16_t
{
    Battery = 0U,
    Resistor = 1U,
    // Add new components here.
};

enum class ParameterType : std::uint16_t
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

#endif  // CIRCUIT_SIM_SRC_COMPONENTS_PARAMETERS