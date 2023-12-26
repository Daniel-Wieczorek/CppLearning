/**
 * @file Resistor.hpp
 * @brief Definition of the Resistor class.
 *
 * @author DWI
 */
#ifndef CIRCUIT_SIM_RESISTOR
#define CIRCUIT_SIM_RESISTOR

#include "IComponent.hpp"
#include "Parameters.hpp"

#include <string>
#include <vector>

namespace circuitsim
{
namespace components
{

class Resistor : public IComponent
{
  public:
    Resistor(ComponentData& component)
        : IComponent(component.name, component.p_terminal, component.n_terminal),
          resistance_{component.parameters[ParameterType::Resistance]} {};
    ~Resistor(){};

    void AddToMnaMatrix(Eigen::MatrixXd& G,
                        Eigen::VectorXd& b,
                        std::map<std::string, uint32_t>& nodes_map,
                        std::uint32_t& src_count) override;

    ComponentVoltageCurrent SimulateOneTick(const double& time_stamp, NodeVoltageMap nodes_matrix) override;

  private:
    double resistance_;
};

}  // namespace components
}  // namespace circuitsim

#endif  // CIRCUIT_SIM_RESISTOR