/**
 * @file Factory.hpp
 * @brief Definition of the Factory class.
 *
 * @author DWI
 */
#ifndef CIRCUIT_SIM_COMPONENT_SRC_COMPONENT_FACTORY
#define CIRCUIT_SIM_COMPONENT_SRC_COMPONENT_FACTORY

#include <memory>
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

    std::unique_ptr<IComponent> createComponent(ComponentData component) const override;
};

}  // namespace components
}  // namespace circuitsim

#endif  // CIRCUIT_SIM_COMPONENT_SRC_COMPONENT_FACTORY