#include <gtest/gtest.h>

#include "array.h"

TEST(array, basic_constructor)
{
    nstd::array<int, 8> arr;
}

TEST(array, size)
{
    nstd::array<int, 8> arr;
    ASSERT_EQ(arr.size(), 8);
}

TEST(array, operator_square_brackets)
{
    nstd::array<int, 8> arr;
    for (std::uint64_t i = 0; i < arr.size(); i++)
        arr[i] = (int)i;

    for (std::uint64_t i = 0; i < arr.size(); i++)
        EXPECT_EQ(arr[i], i);
}

TEST(array, iterators)
{
    nstd::array<int, 8> arr;

    for (auto& val : arr)
        val = 1;

    for (const int value : arr)
        EXPECT_EQ(value, 1);
}

TEST(array, initializer_list_smaller_than_template_size_constructor)
{
    nstd::array<int, 8> arr{ 1, 1, 1, 1 };

    for (int i = 0; i < 4; i++)
        EXPECT_EQ(arr[i], 1);

    for (int i = 4; i < 8; i++)
        EXPECT_EQ(arr[i], 0);
}

TEST(array, initializer_list_assign)
{
    nstd::array<int, 2> arr = { 1, 1, 1, 1 };

    for (const int value : arr)
        EXPECT_EQ(value, 1);
}