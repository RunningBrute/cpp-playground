cmake_minimum_required(VERSION 3.14)
project(reverse_string)

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
set(SOURCE_FILES reverse_string.cpp)

add_executable(
  reverse_string_test
  ${SOURCE_FILES}
  reverse_string_test.cpp
)
target_link_libraries(
  reverse_string_test
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(reverse_string_test)