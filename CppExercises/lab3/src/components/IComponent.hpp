/**
 * @file Component.hpp
 * @brief Definition of the Component class.
 *
 * @author DWI
 */
#ifndef CIRCUIT_SIM_I_COMPONENT
#define CIRCUIT_SIM_I_COMPONENT

#include <cstdint>
#include <map>
#include <string>
#include <vector>

#include <Eigen/Dense>

namespace circuitsim
{
namespace components
{

using ComponentVoltageCurrent = std::pair<double, double>;
using NodeVoltageMap = std::map<std::string, double>;

// Component interface
class IComponent
{
  public:
    IComponent(std::string name, std::string p_terminal, std::string n_terminal)
        : name_{name}, p_terminal_{p_terminal}, n_terminal_{n_terminal} {};

    virtual ~IComponent(){};

    IComponent(const IComponent&) = delete;
    IComponent(IComponent&&) = delete;
    IComponent& operator=(const IComponent&) = delete;
    IComponent& operator=(IComponent&&) = delete;

    // @brief Add component to Modified Nodal Analysis Matrix
    // @note: Check for reference: https://lpsa.swarthmore.edu/Systems/Electrical/mna/MNA3.html
    virtual void AddToMnaMatrix(Eigen::MatrixXd& G,
                                Eigen::VectorXd& b,
                                std::map<std::string, uint32_t>& nodes_map,
                                std::uint32_t& src_count) = 0;

    virtual ComponentVoltageCurrent SimulateOneTick(const double& time_stamp, NodeVoltageMap nodes_matrix) = 0;

  public:
    // @brief Return voltage through the component
    double GetVoltage(NodeVoltageMap& nodes_matrix) { return (nodes_matrix[p_terminal_] - nodes_matrix[n_terminal_]); }

    // @brief Return name of the component
    std::string GetName() const { return name_; }

    // @brief Return name of terminals for each component
    std::pair<std::string, std::string> GetTerminals() { return std::make_pair(p_terminal_, n_terminal_); }

  private:
    std::string name_;
    std::string p_terminal_;
    std::string n_terminal_;
};

}  // namespace components
}  // namespace circuitsim

#endif  // CIRCUIT_SIM_I_COMPONENT