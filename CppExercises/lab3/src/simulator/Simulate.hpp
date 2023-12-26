/**
 * @file Simulate.hpp
 * @brief Definition of the Simulate class.
 *
 * @author DWI
 */
#ifndef CIRCUIT_SIM_SIMULATE
#define CIRCUIT_SIM_SIMULATE

#include "Circuit.hpp"

#include <map>

namespace circuitsim
{
namespace application
{

class Simulate
{
  public:
    Simulate(CircuitPtr& circuit) : circuit_(std::move(circuit)) {}
    ~Simulate(){};

    // @brief Run circuit simulation
    int32_t Run(const std::uint32_t& num_of_iterations,
                const std::uint32_t& iterations_printable,
                const double& iteration_time_step);

    void PrintComponentHeader(const std::vector<std::string>& data);
    void PrintComponentData(const ComponentsParamMap& data);

  private:
    CircuitPtr circuit_;
    Nodes nodes_;
};

}  // namespace application
}  // namespace circuitsim
#endif  // CIRCUIT_SIM_CIRCUIT_SIMULATOR_CIRCUIT