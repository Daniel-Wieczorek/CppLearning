/**
 * @file Factory.hpp
 * @brief Definition of the Factory class.
 *
 * @author DWI
 */
#ifndef CIRCUIT_SIM_COMPONENT_SRC_BASE_COMPONENT_HPP
#define CIRCUIT_SIM_COMPONENT_SRC_BASE_COMPONENT_HPP

#include "IComponent.hpp"
#include "Parameters.hpp"

#include <string>

namespace circuitsim
{
namespace components
{

class BaseComponent : public IComponent
{
  public:
    BaseComponent(const ComponentData& component)
        : name_(component.name), p_terminal_(component.p_terminal), n_terminal_(component.n_terminal){};

    virtual ~BaseComponent() = default;

    double GetVoltage(NodeVoltageMap& nodes_matrix) noexcept override
    {
        return (nodes_matrix[p_terminal_] - nodes_matrix[n_terminal_]);
    }

    std::string GetName() const noexcept override { return name_; }

    std::pair<std::string, std::string> GetTerminals() const noexcept override
    {
        return std::make_pair(p_terminal_, n_terminal_);
    }

  private:
    std::string name_;
    std::string p_terminal_;
    std::string n_terminal_;
};

}  // namespace components
}  // namespace circuitsim

#endif  // CIRCUIT_SIM_COMPONENT_SRC_BASE_COMPONENT_HPP