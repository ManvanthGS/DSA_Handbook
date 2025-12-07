/**
 * @file array_test.cpp
 * @brief Unit tests for the Array data structure.
 *
 * This file contains comprehensive test cases for the fixed-size Array class,
 * covering element access, bounds checking, and utility functions.
 */

#include "data_structures/arrays/array.hpp"
#include <gtest/gtest.h>

/**
 * @brief Test that elements can be accessed and modified within bounds.
 */
TEST(ArrayTest, ElementAccessWithinBounds)
{
    dsa_handbook::Array<int, 3> arr;
    arr[0] = 10;
    arr[1] = 20;
    arr[2] = 30;

    EXPECT_EQ(arr[0], 10);
    EXPECT_EQ(arr[1], 20);
    EXPECT_EQ(arr[2], 30);
}

/**
 * @brief Test that accessing elements out of bounds throws std::out_of_range.
 */
TEST(ArrayTest, ElementAccessOutOfBounds)
{
    dsa_handbook::Array<int, 3> arr;

    EXPECT_THROW(arr[3] = 40, std::out_of_range);
    EXPECT_THROW(int value = arr[4], std::out_of_range);
}

/**
 * @brief Test const element access on a const Array reference.
 */
TEST(ArrayTest, ConstElementAccess)
{
    dsa_handbook::Array<int, 2> arr;
    arr[0] = 5;
    arr[1] = 15;

    const dsa_handbook::Array<int, 2>& constArr = arr;

    EXPECT_EQ(constArr[0], 5);
    EXPECT_EQ(constArr[1], 15);
}

/**
 * @brief Test that size() returns the correct compile-time size.
 */
TEST(ArrayTest, SizeFunction)
{
    dsa_handbook::Array<double, 5> arr;
    EXPECT_EQ(arr.size(), 5);

    dsa_handbook::Array<char, 10> arr2;
    EXPECT_EQ(arr2.size(), 10);
}

/**
 * @brief Test that data_ptr() returns a valid pointer to the underlying data.
 */
TEST(ArrayTest, DataPointerAccess)
{
    dsa_handbook::Array<int, 3> arr;
    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 3;

    int* ptr = arr.data_ptr();
    EXPECT_EQ(ptr[0], 1);
    EXPECT_EQ(ptr[1], 2);
    EXPECT_EQ(ptr[2], 3);
}

/**
 * @brief Test that const data_ptr() works on const Arrays.
 */
TEST(ArrayTest, ConstDataPointerAccess)
{
    dsa_handbook::Array<int, 2> arr;
    arr[0] = 100;
    arr[1] = 200;

    const dsa_handbook::Array<int, 2>& constArr = arr;
    const int* ptr = constArr.data_ptr();
    EXPECT_EQ(ptr[0], 100);
    EXPECT_EQ(ptr[1], 200);
}

/**
 * @brief Test default initialization of array elements.
 */
TEST(ArrayTest, DefaultInitialization)
{
    dsa_handbook::Array<int, 3> arr;
    EXPECT_EQ(arr[0], 0);
    EXPECT_EQ(arr[1], 0);
    EXPECT_EQ(arr[2], 0);
}

/**
 * @brief Test with different data types (string simulation with char).
 */
TEST(ArrayTest, DifferentDataTypes)
{
    dsa_handbook::Array<double, 2> doubleArr;
    doubleArr[0] = 3.14;
    doubleArr[1] = 2.71;

    EXPECT_DOUBLE_EQ(doubleArr[0], 3.14);
    EXPECT_DOUBLE_EQ(doubleArr[1], 2.71);
}
