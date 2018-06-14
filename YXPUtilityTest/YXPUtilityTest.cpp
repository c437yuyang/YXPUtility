#include <gtest/gtest.h>
#include <YXPUtility>
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


TEST(HeapTest, demo1)
{
	Heap<int> h;
	h.push(1);
	h.push(2);
	EXPECT_EQ(h.size(), 2);
	EXPECT_EQ(h.pop(), 1);
	EXPECT_EQ(h.size(), 1);
}

TEST(HeapTest, demo2)
{
	Heap<int, std::less<int>> h;
	h.push(1);
	h.push(2);
	EXPECT_EQ(h.size(), 2);
	EXPECT_EQ(h.pop(), 2);
	EXPECT_EQ(h.size(), 1);
}

TEST(HeapTest, demo3)
{
	std::vector<int> v{ 5, 4, 3, 2, 1 };
	Heap<int, std::less<int>> h(v);

	EXPECT_EQ(h.size(), v.size());
	EXPECT_EQ(h.pop(), 5);
	EXPECT_EQ(h.pop(), 4);
	EXPECT_EQ(h.pop(), 3);
	EXPECT_EQ(h.pop(), 2);
	EXPECT_EQ(h.pop(), 1);
}

TEST(RandomHelperTest, demo1)
{
	yxp_utility::RandomHelper::initSeed();
	auto v = yxp_utility::RandomHelper::randomMatrix(5, 5, -10, 10);
	yxp_utility::ArrayHelper::printMatrix(v);
	int * p = new int[5 * 5];
	yxp_utility::RandomHelper::randomMatrix(p, 5, 5, -10, 10);
	yxp_utility::ArrayHelper::printMatrix(p, 5, 5);
	assert(v.size() == 5);
}




int main(int argc, char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
	//用ctrl+f5执行就不会一闪而过了
}
