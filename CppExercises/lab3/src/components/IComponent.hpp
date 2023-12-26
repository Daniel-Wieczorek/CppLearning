/**
 * @file Component.hpp
 * @brief Definition of the Component class.
 *
 * @author DWI
 */
#ifndef CIRCUIT_SIM_I_COMPONENT
#define CIRCUIT_SIM_I_COMPONENT

#include <Eigen/Dense>

#include <cstdint>
#include <map>
#include <string>
#include <vector>

namespace circuitsim
{
namespace components
{

using ComponentVoltageCurrent = std::pair<double, double>;
using NodeVoltageMap = std::map<std::string, double>;
using NodesMap = std::map<std::string, uint32_t>;
// Component interface
class IComponent
{
  public:
    IComponent() = default;
    virtual ~IComponent() = default;

    IComponent(const IComponent&) = delete;
    IComponent(IComponent&&) = delete;
    IComponent& operator=(const IComponent&) = delete;
    IComponent& operator=(IComponent&&) = delete;

    // @brief Add component to Modified Nodal Analysis Matrix
    // @note: Check for reference: https://lpsa.swarthmore.edu/Systems/Electrical/mna/MNA3.html
    virtual void AddToMnaMatrix(Eigen::MatrixXd& G,
                                Eigen::VectorXd& b,
                                NodesMap& nodes_map,
                                std::uint32_t& src_count) noexcept = 0;

    // @brief Simulate one tick of the component
    virtual ComponentVoltageCurrent SimulateOneTick(const double& time_stamp,
                                                    NodeVoltageMap& nodes_matrix) noexcept = 0;

    // @brief Return voltage through the component
    virtual double GetVoltage(NodeVoltageMap& nodes_matrix) noexcept = 0;

    // @brief Return name of the component
    virtual std::string GetName() const noexcept = 0;

    // @brief Return name of terminals for each component
    virtual std::pair<std::string, std::string> GetTerminals() const noexcept = 0;
};

}  // namespace components
}  // namespace circuitsim

#endif  // CIRCUIT_SIM_I_COMPONENT