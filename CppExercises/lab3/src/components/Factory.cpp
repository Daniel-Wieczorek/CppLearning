/**
 * @file ComponentFactory.cpp
 *
 * @author DWI
 * @date 2021-12-12
 */

#include "Battery.hpp"
#include "Factory.hpp"
#include "Resistor.hpp"

#include <memory>

namespace circuitsim
{
namespace components
{

std::optional<std::unique_ptr<IComponent>> Factory::createComponent(ComponentData& component) const noexcept
{
    switch (component.type)
    {
        case ElectricComponent::Battery:
            return std::make_unique<Battery>(component);
        case ElectricComponent::Resistor:
            return std::make_unique<Resistor>(component);
        default:
            return std::nullopt;
    }
}

}  // namespace components
}  // namespace circuitsim
