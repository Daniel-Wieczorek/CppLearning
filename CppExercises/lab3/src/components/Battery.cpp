/**
 * @file Battery.cpp
 *
 * @author DWI
 * @date 2021-12-12
 */

#include "Battery.hpp"

namespace circuitsim
{
namespace components
{

void Battery::AddToMnaMatrix(Eigen::MatrixXd& G,
                             Eigen::VectorXd& b,
                             NodesMap& nodes_map,
                             std::uint32_t& src_count) noexcept
{
    const int64_t n1 = (GetTerminals().first == "n") ? -1 : nodes_map[GetTerminals().first];
    const int64_t n2 = (GetTerminals().second == "n") ? -1 : nodes_map[GetTerminals().second];
    const uint32_t offset = static_cast<uint32_t>(nodes_map.size());

    if (n1 >= 0)
    {
        G(n1, src_count + offset) = 1;
        G(src_count + offset, n1) = 1;
        b(src_count + offset) = voltage_;
    }
    if (n2 >= 0)
    {
        G(n2, src_count + offset) = -1;
        G(src_count + offset, n2) = -1;
        b(src_count + offset) -= voltage_;
    }
    ++src_count;
}

ComponentVoltageCurrent Battery::SimulateOneTick(const double& time_stamp, NodeVoltageMap& nodes_matrix) noexcept
{
    return std::make_pair(GetVoltage(nodes_matrix), 0.0);
}

}  // namespace components
}  // namespace circuitsim
