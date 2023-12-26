/**
 * @file Factory.hpp
 * @brief Definition of the Factory class.
 *
 * @author DWI
 */
#ifndef CIRCUIT_SIM_COMPONENT_SRC_COMPONENT_FACTORY
#define CIRCUIT_SIM_COMPONENT_SRC_COMPONENT_FACTORY

#include "IFactory.hpp"

namespace circuitsim
{
namespace components
{

class Factory : public IFactory
{
  public:
    Factory() = default;
    ~Factory() = default;

    std::optional<std::unique_ptr<IComponent>> createComponent(ComponentData& component) const noexcept override;
};

}  // namespace components
}  // namespace circuitsim

#endif  // CIRCUIT_SIM_COMPONENT_SRC_COMPONENT_FACTORY