/**
 * @file ComponentFactory.hpp
 * @brief Definition of the interfaceComponentFactory class.
 *
 * @author DWI
 */
#ifndef CIRCUIT_SIM_COMPONENT_SRC_I_FACTORY_HPP
#define CIRCUIT_SIM_COMPONENT_SRC_I_FACTORY_HPP

#include "IComponent.hpp"
#include "Parameters.hpp"

#include <memory>
#include <optional>

namespace circuitsim
{
namespace components
{

class IFactory
{
  public:
    IFactory() = default;
    virtual ~IFactory() = default;

    virtual std::optional<std::unique_ptr<IComponent>> createComponent(ComponentData& component) const noexcept = 0;
};

}  // namespace components
}  // namespace circuitsim

#endif  // CIRCUIT_SIM_COMPONENT_SRC_I_FACTORY_HPP