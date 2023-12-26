/**
 * @file main.cpp
 *
 * For detailed description and usage check CircuitSimulator.h
 *
 * All the tests are written in Catch2 and placed in: `test/LinkedListTest.cpp`
 *
 * @todo Write mocks for circuit simulator
 * @todo Write all the unit tests (test/LinkedListTest.cpp)
 *
 * @author DWI
 * @date 2021-12-12
 */

#include "Application.hpp"

int main(int argc, char* argv[])
{
    auto simulator = circuitsim::application::Application();
    return simulator.RunSimulation(argc, argv);
}
