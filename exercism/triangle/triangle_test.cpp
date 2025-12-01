#include <gtest/gtest.h>
#include "triangle.hpp"

TEST(Triangle, equilateral_triangles_have_equal_sides)
{
    EXPECT_TRUE(triangle::flavor::equilateral == triangle::kind(2, 2, 2));
}

TEST(Triangle, larger_equilateral_triangles_also_have_equal_sides)
{
    EXPECT_TRUE(triangle::flavor::equilateral == triangle::kind(10, 10, 10));
}

TEST(Triangle, isosceles_triangles_have_last_two_sides_equal)
{
    EXPECT_TRUE(triangle::flavor::isosceles == triangle::kind(3, 4, 4));
}

TEST(Triangle, isosceles_triangles_have_first_and_last_sides_equal)
{
    EXPECT_TRUE(triangle::flavor::isosceles == triangle::kind(4, 3, 4));
}

TEST(Triangle, isosceles_triangles_have_first_two_sides_equal)
{
    EXPECT_TRUE(triangle::flavor::isosceles == triangle::kind(4, 4, 3));
}

TEST(Triangle, isosceles_triangles_have_in_fact_exactly_two_sides_equal)
{
    EXPECT_TRUE(triangle::flavor::isosceles == triangle::kind(10, 10, 2));
}

TEST(Triangle, scalene_triangles_have_no_equal_sides)
{
    EXPECT_TRUE(triangle::flavor::scalene == triangle::kind(3, 4, 5));
}

TEST(Triangle, scalene_triangles_have_no_equal_sides_at_a_larger_scale_too)
{
    EXPECT_TRUE(triangle::flavor::scalene == triangle::kind(10, 11, 12));
}

TEST(Triangle, scalene_triangles_have_no_equal_sides_in_descending_order_either)
{
    EXPECT_TRUE(triangle::flavor::scalene == triangle::kind(5, 4, 2));
}

TEST(Triangle, very_small_triangles_are_legal)
{
    EXPECT_TRUE(triangle::flavor::scalene == triangle::kind(0.4, 0.6, 0.3));
}

TEST(Triangle, triangles_with_no_size_are_illegal)
{
    EXPECT_THROW(triangle::kind(0, 0, 0), std::domain_error);
}

TEST(Triangle, triangles_with_negative_sides_are_illegal)
{
    EXPECT_THROW(triangle::kind(3, 4, -5), std::domain_error);
}

TEST(Triangle, triangles_violating_triangle_inequality_are_illegal)
{
    EXPECT_THROW(triangle::kind(1, 1, 3), std::domain_error);
}

TEST(Triangle, larger_triangles_violating_triangle_inequality_are_illegal)
{
    EXPECT_THROW(triangle::kind(7, 3, 2), std::domain_error);
}

TEST(Triangle, double_and_integer_arguments)
{
    EXPECT_TRUE(triangle::flavor::scalene == triangle::kind(5.5, 4, 2));
}