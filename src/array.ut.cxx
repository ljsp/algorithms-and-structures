#include <gtest/gtest.h>

#include "array.h"

#include <array>

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

TEST(array, initializer_list_assign)
{
    nstd::array<int, 4> arr = { 1, 1, 1, 1 };

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

// Stack is usually 1Mo on Windows and 8Mo on Linux
// Allocating more than that causes a stack overflow
TEST(array, allocate_512ko_on_the_stack)
{
    nstd::array<int, 512 * 1024 / sizeof(int)> arr;

    for (auto& val : arr)
        val = 1;

    for (const int value : arr)
        EXPECT_EQ(value, 1);
}

// To allocate more elements they must be stored on the heap as below
TEST(array, allocate_16Mo_on_the_heap)
{
    constexpr std::uint64_t alloc_size = 16 * 1024 * 1024 / sizeof(int);

    auto* arr = new nstd::array<int, alloc_size>;

    for (auto& val : *arr)
        val = 1;

    for (const int value : *arr)
        EXPECT_EQ(value, 1);

    delete arr;
    arr = nullptr;
}