cmake_minimum_required(VERSION 3.15)
project(LinkedListTest
    VERSION 1.0
    DESCRIPTION "Catch2 tests for LinkedList"
    LANGUAGES CXX)

find_package(Catch2 3 REQUIRED)
add_executable(tests LinkedListTest.cpp)
target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)
