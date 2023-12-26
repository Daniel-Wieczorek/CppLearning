/**
 * @file Circuit.hpp
 * @brief Definition of the Circuit class.
 *
 * @author DWI
 */
#ifndef CIRCUIT_SIM_CIRCUIT
#define CIRCUIT_SIM_CIRCUIT

#include "src/components/Factory.hpp"
#include "src/components/IComponent.hpp"
#include "src/components/Parameters.hpp"

#include <map>
#include <memory>
#include <optional>
#include <string>
#include <vector>

namespace circuitsim
{
namespace application
{

class Circuit;
using CircuitPtr = std::unique_ptr<Circuit>;
using ComponentVoltageCurrent = std::pair<double, double>;
using ComponentsParamMap = std::map<std::string, ComponentVoltageCurrent>;
using Nodes = circuitsim::components::NodesMap;
class Circuit
{
  public:
    Circuit(){};
    ~Circuit(){};

    // @brief Add components to the circuit
    void AddComponent(circuitsim::components::ComponentData& component) noexcept;

    // @brief Solve the circuit
    std::int32_t Resolve();

    // @brief Get Map of all components state for given timestamp
    void GetComponentsParameters(const double& time_stamp, ComponentsParamMap& components_params);

    std::vector<std::string> GetComponentsNames();

  private:  // private methods:
    std::optional<int> Validate();
    void CreateNodesArray();
    std::int32_t CountVoltageSources();

  private:
    std::vector<std::unique_ptr<circuitsim::components::IComponent>> components_;
    Nodes nodes_;
    circuitsim::components::NodeVoltageMap nodes_voltages_;
    circuitsim::components::Factory factory_;
};

}  // namespace application

}  // namespace circuitsim

#endif  // CIRCUIT_SIM_CIRCUIT