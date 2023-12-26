/**
 * @file ComponentFactory.hpp
 * @brief Definition of the interfaceComponentFactory class.
 *
 * @author DWI
 */
#ifndef CIRCUIT_SIM_COMPONENT_SRC_I_COMPONENT_FACTORY
#define CIRCUIT_SIM_COMPONENT_SRC_I_COMPONENT_FACTORY

#include <memory>
#include "IComponent.hpp"
#include "Parameters.hpp"

namespace circuitsim
{
namespace components
{

class IFactory
{
  public:
    virtual ~IFactory() = default;

    virtual std::unique_ptr<IComponent> createComponent(ComponentData component) const = 0;
};

}  // namespace components
}  // namespace circuitsim

#endif  // CIRCUIT_SIM_COMPONENT_SRC_I_COMPONENT_FACTORY