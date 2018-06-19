#include <gtest/gtest.h>
#include "DataStructures/Array.h"
using namespace yxp_utility;

TEST(Array1DTest, demo1)
{
	Array1D<int> arr1d(10);

	auto arr1d_1 = arr1d;
	EXPECT_EQ(memcmp(arr1d.elem_, arr1d_1.elem_, 10 * 4), 0);
	arr1d[9] = 10;

	EXPECT_EQ(arr1d[9], 10);
	EXPECT_EQ(arr1d_1[9], 0);

	Array1D<int> arr1d_2(1);
	arr1d_2 = arr1d;
	EXPECT_EQ(arr1d_2[9], 10);
	EXPECT_EQ(memcmp(arr1d.elem_, arr1d_2.elem_, 10 * 4), 0);
}


TEST(Array2DTest, demo1)
{
	Array2D<int> arr2d(10, 10);

	auto arr2d_1 = arr2d;
	EXPECT_EQ(memcmp(arr2d.elem_, arr2d_1.elem_, 10 * 10 * 4), 0);
	arr2d[9][9] = 10;

	EXPECT_EQ(arr2d[9][9], 10);
	EXPECT_EQ(arr2d_1[9][9], 0);

	Array2D<int> arr2d_2(1, 1);
	arr2d_2 = arr2d;
	EXPECT_EQ(arr2d_2[9][9], 10);
	EXPECT_EQ(memcmp(arr2d.elem_, arr2d_2.elem_, 10 * 10 * 4), 0);
}