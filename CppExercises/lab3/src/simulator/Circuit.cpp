/**
 * @file Circuit.cpp
 *
 * @author DWI
 * @date 2021-12-12
 */

#include "Circuit.hpp"
#include "src/components/Factory.hpp"

#include <algorithm>
#include <iostream>
#include <memory>
#include <set>
#include <vector>

namespace circuitsim
{
namespace application
{

void Circuit::AddComponent(circuitsim::components::ComponentData& component) noexcept
{
    components_.push_back(factory_.createComponent(component));
}

std::int32_t Circuit::Validate()
{
    // check for short circuit:

    // TODO: FIX it: check for duplicated components:
    std::sort(components_.begin(), components_.end());
    auto result = std::unique(components_.begin(), components_.end()) - components_.begin();
    std::cerr << "Number of components: " << result << std::endl;
    return result;
}

void Circuit::CreateNodesArray()
{
    uint32_t cnt{};

    for (const auto& element : components_)
    {
        std::vector<std::string> terminals{element->GetTerminals().first, element->GetTerminals().second};
        for (const auto& terminal : terminals)
        {
            if (terminal == "n")
            {
                continue;
            }
            if (nodes_.find(terminal) == nodes_.end())
            {
                nodes_[terminal] = cnt++;
            }
        }
    }
}

std::int32_t Circuit::Resolve()
{
    if (Validate() == -1)
    {
        return EXIT_FAILURE;
    }

    CreateNodesArray();
    std::int32_t numNodes = nodes_.size();
    std::int32_t numVsources = 1;

    // Matrix size
    int matrixSize = numNodes + numVsources;

    // Initialize G matrix and b vector
    Eigen::MatrixXd G = Eigen::MatrixXd::Zero(matrixSize, matrixSize);
    Eigen::VectorXd b = Eigen::VectorXd::Zero(matrixSize);

    // Add elements to the matrix
    uint32_t voltage_src{0};
    for (auto& element : components_)
    {
        element->AddToMnaMatrix(G, b, nodes_, voltage_src);
    }

    // Eigen::IOFormat CleanFmt(4, 0, ", ", "\n", "[", "]");
    // std::cerr << G.format(CleanFmt) << std::endl;
    // std::cerr << b.format(CleanFmt) << std::endl;

    Eigen::VectorXd x = G.colPivHouseholderQr().solve(b);

    for (const auto& [node, value] : nodes_)
    {
        nodes_voltages_.insert({node, x(value)});
    }

    return EXIT_SUCCESS;
}

void Circuit::GetComponentsParameters(const double& time_stamp, ComponentsParamMap& components_params)
{
    components_params.clear();
    for (const auto& component : components_)
    {
        components_params[component->GetName()] = component->SimulateOneTick(time_stamp, nodes_voltages_);
    }
}

std::vector<std::string> Circuit::GetComponentsNames()
{
    std::vector<std::string> component_names{};
    for (const auto& component : components_)
    {
        component_names.push_back(component->GetName());
    }

    return component_names;
}

}  // namespace application
}  // namespace circuitsim
