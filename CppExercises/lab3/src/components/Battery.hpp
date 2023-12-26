/**
 * @file Battery.hpp
 * @brief Definition of the Battery class.
 *
 * @author DWI
 */
#ifndef CIRCUIT_SIM_BATTERY
#define CIRCUIT_SIM_BATTERY

#include <map>
#include <string>
#include <vector>

#include <Eigen/Dense>

#include "IComponent.hpp"
#include "Parameters.hpp"

namespace circuitsim
{
namespace components
{

class Battery : public IComponent
{
  public:
    Battery(ComponentData& component)
        : IComponent(component.name, component.p_terminal, component.n_terminal),
          voltage_{component.parameters[ParameterType::Voltage]} {};
    ~Battery(){};

    void AddToMnaMatrix(Eigen::MatrixXd& G,
                        Eigen::VectorXd& b,
                        std::map<std::string, uint32_t>& nodes_map,
                        std::uint32_t& src_count) override;

    ComponentVoltageCurrent SimulateOneTick(const double& time_stamp, NodeVoltageMap nodes_matrix) override;

  private:
    double voltage_;
};

}  // namespace components
}  // namespace circuitsim

#endif  // CIRCUIT_SIM_BATTERY