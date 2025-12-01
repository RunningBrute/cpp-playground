#include <gtest/gtest.h>
#include "hello_world.hpp"

TEST(HelloWorldTest, BasicAssertions)
{
  EXPECT_TRUE(hello_world::hello() == "Hello, World!");
}