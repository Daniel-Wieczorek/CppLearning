/**
 * @file main.cpp
 * @brief Implementation of the LinkedList class.
 *
 * For detailed description and usage check LinkedList.h
 *
 * All the tests are written in Catch2 and placed in: `test/LinkedListTest.cpp`
 *
 * @todo Write mocks for library
 * @todo Write all the unit tests (test/LinkedListTest.cpp)
 *
 * @author DWI
 * @date 2021-12-12
 */

#include <iostream>
#include "LinkedList.h"

int main()
{
    saab::library::LinkedList<std::uint32_t> list;
    list.Insert(21);
    std::cout << "LinkedList library started and printed: ";
    list.Print();
    return 0;
}
