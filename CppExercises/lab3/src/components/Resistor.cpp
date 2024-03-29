/**
 * @file Resistor.cpp
 *
 * @author DWI
 * @date 2021-12-12
 */

#include "Resistor.hpp"

#include <iostream>
#include <vector>

namespace circuitsim
{
namespace components
{

void Resistor::AddToMnaMatrix(Eigen::MatrixXd& G,
                              Eigen::VectorXd& /*b*/,
                              std::map<std::string, uint32_t>& nodes_map,
                              std::uint32_t& /*src_count*/)
{
    const int32_t n1 = (GetTerminals().first == "n") ? -1 : nodes_map[GetTerminals().first];
    const int32_t n2 = (GetTerminals().second == "n") ? -1 : nodes_map[GetTerminals().second];

    double conductance = 1.0 / resistance_;
    if (n1 >= 0)
    {
        G(n1, n1) += conductance;
        if (n2 >= 0)
        {
            G(n1, n2) -= conductance;
            G(n2, n1) -= conductance;
        }
    }
    if (n2 >= 0)
    {
        G(n2, n2) += conductance;
    }
}

ComponentVoltageCurrent Resistor::SimulateOneTick(const double& time_stamp, NodeVoltageMap nodes_matrix)
{
    const double voltage_difference = this->GetVoltage(nodes_matrix);
    const double max_current = resistance_ / voltage_difference;

    static double sim_current = 0.0;
    sim_current += max_current * time_stamp;

    if (sim_current < max_current)
    {
        return std::make_pair(voltage_difference, sim_current);
    }

    return std::make_pair(voltage_difference, max_current);
}

}  // namespace components

}  // namespace circuitsim
