cmake_minimum_required(VERSION 3.14)
project(leap)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 17)

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG release-1.12.1
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

# Add main.cpp file of project root directory as source file
set(SOURCE_FILES leap.cpp)

add_executable(
  leap_test
  ${SOURCE_FILES}
  leap_test.cpp
)
target_link_libraries(
  leap_test
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(leap_test)