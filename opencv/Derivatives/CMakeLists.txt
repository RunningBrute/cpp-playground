project(Derivatives)
cmake_minimum_required(VERSION 3.14)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS}) #not needed for CMake >= 2.8.11

add_executable(Derivatives Derivatives.cpp)
target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS} )