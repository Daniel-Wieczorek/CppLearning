/**
 * @file Battery.hpp
 * @brief Definition of the Battery class.
 *
 * @author DWI
 */
#ifndef CIRCUIT_SIM_SRC_COMPONENTS_BATTERY_HPP
#define CIRCUIT_SIM_SRC_COMPONENTS_BATTERY_HPP

#include "BaseComponent.hpp"
#include "Parameters.hpp"

#include <Eigen/Dense>
#include <map>
#include <string>
#include <vector>

namespace circuitsim
{
namespace components
{

class Battery : public BaseComponent
{
  public:
    Battery(ComponentData& component) : BaseComponent(component), voltage_{component.parameters[ParameterType::Voltage]}
    {
        assert(voltage_ > 0);
    };

    ~Battery(){};

    void AddToMnaMatrix(Eigen::MatrixXd& G,
                        Eigen::VectorXd& b,
                        NodesMap& nodes_map,
                        std::uint32_t& src_count) noexcept override;

    ComponentVoltageCurrent SimulateOneTick(const double& time_stamp, NodeVoltageMap& nodes_matrix) noexcept override;

  private:
    double voltage_;
};

}  // namespace components
}  // namespace circuitsim

#endif  // CIRCUIT_SIM_SRC_COMPONENTS_BATTERY_HPP