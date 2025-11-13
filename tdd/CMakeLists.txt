cmake_minimum_required(VERSION 3.15)
project(tdd_basic LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

find_package(Catch2 CONFIG REQUIRED)

add_library(calculator src/calculator.cpp inc/calculator.hpp)
target_include_directories(calculator PUBLIC inc)

add_executable(test_calculator_catch2 tests/test_calculator_catch2.cpp)
target_link_libraries(test_calculator_catch2 PRIVATE calculator Catch2::Catch2WithMain)

add_executable(test_calculator_gtest tests/test_calculator_gtest.cpp)
target_link_libraries(test_calculator_gtest PRIVATE calculator gtest_main gmock_main)

include(CTest)
include(Catch)
include(GoogleTest)
catch_discover_tests(test_calculator_catch2 test_calculator_gtest)

enable_testing()
