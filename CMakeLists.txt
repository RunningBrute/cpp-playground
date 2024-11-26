cmake_minimum_required(VERSION 3.15)
project(LeetCodeSolutions LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(${CMAKE_BINARY_DIR}/conan_toolchain.cmake)

# Find packages from Conan
list(APPEND CMAKE_MODULE_PATH ${CMAKE_BINARY_DIR})
find_package(Catch2 CONFIG REQUIRED)

include(CTest)

add_subdirectory(src)