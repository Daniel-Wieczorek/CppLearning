cmake_minimum_required(VERSION 3.15)
project(TimeHandlerTest
    VERSION 1.0
    DESCRIPTION "Catch2 tests for TimeHandler"
    LANGUAGES CXX)

find_package(Catch2 3 REQUIRED)
add_library(TimeHandlerLib ../TimeHandler.cpp ../TimeHandler.h )
add_executable(tests TimeHandlerTest.cpp)
target_link_libraries(tests PRIVATE Catch2::Catch2WithMain TimeHandlerLib)
