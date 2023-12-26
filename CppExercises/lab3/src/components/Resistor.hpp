/**
 * @file Resistor.hpp
 * @brief Definition of the Resistor class.
 *
 * @author DWI
 */
#ifndef CIRCUIT_SIM_SRC_COMPONENTS_RESISTOR_HPP
#define CIRCUIT_SIM_SRC_COMPONENTS_RESISTOR_HPP

#include "BaseComponent.hpp"
#include "Parameters.hpp"

#include <string>
#include <vector>

namespace circuitsim
{
namespace components
{

class Resistor : public BaseComponent
{
  public:
    Resistor(ComponentData& component)
        : BaseComponent(component), resistance_(component.parameters[ParameterType::Resistance])
    {
        assert(resistance_ > 0);
    };

    ~Resistor() = default;

    void AddToMnaMatrix(Eigen::MatrixXd& G,
                        [[maybe_unused]] Eigen::VectorXd& b,
                        NodesMap& nodes_map,
                        [[maybe_unused]] std::uint32_t& src_count) noexcept override;

    ComponentVoltageCurrent SimulateOneTick(const double& time_stamp, NodeVoltageMap& nodes_matrix) noexcept override;

  private:
    double resistance_;
};

}  // namespace components
}  // namespace circuitsim

#endif  // CIRCUIT_SIM_SRC_COMPONENTS_RESISTOR_HPP