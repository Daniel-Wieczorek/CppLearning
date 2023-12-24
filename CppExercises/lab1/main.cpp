/**
 * @file main.cpp
 *
 * For detailed description and usage check TimeHandler.h
 *
 * All the tests are written in Catch2 and placed in: `test/TimeHandlerTest.cpp`
 *
 * @todo Write mocks for library
 * @todo Write all the unit tests (test/TimeHandlerTest.cpp)
 *
 * @author DWI
 * @date 2021-12-12
 */

#include <iostream>

#include "TimeHandler.h"

int main()
{
    saab::library::TimeHandler obj_(12u, 21u, 21u);
    std::cout << "It is just quick time check: " << obj_ << std::endl;
    return 0;
}
