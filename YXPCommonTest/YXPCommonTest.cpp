#include <gtest/gtest.h>
#include <YXPCommon.h>
using namespace yxp_utility;
TEST(HeapTest, demo1)
{
	
	Heap<int> h;
	h.Push(1);
	h.Push(2);
	EXPECT_EQ(h.size(), 2);
	EXPECT_EQ(h.Pop(), 1);
	EXPECT_EQ(h.size(), 1);
}

TEST(HeapTest, demo2)
{
	Heap<int, std::less<int>> h;
	h.Push(1);
	h.Push(2);
	EXPECT_EQ(h.size(), 2);
	EXPECT_EQ(h.Pop(), 2);
	EXPECT_EQ(h.size(), 1);
}

TEST(HeapTest, demo3)
{
	std::vector<int> v{5, 4, 3, 2, 1};
	Heap<int, std::less<int>> h(v);

	EXPECT_EQ(h.size(), v.size());
	EXPECT_EQ(h.Pop(), 5);
	EXPECT_EQ(h.Pop(), 4);
	EXPECT_EQ(h.Pop(), 3);
	EXPECT_EQ(h.Pop(), 2);
	EXPECT_EQ(h.Pop(), 1);
}

TEST(RandomHelperTest, demo1) 
{
	yxp_utility::RandomHelper::initSeed();
	auto v = yxp_utility::RandomHelper::randomMatrix(5, 5, -10, 10);
	yxp_utility::ArrayHelper::printMatrix(v);
	int * p = new int[5 * 5];
	yxp_utility::RandomHelper::randomMatrix(p, 5, 5, -10, 10);
	yxp_utility::ArrayHelper::printMatrix(p,5,5);
	assert(v.size() == 5);
}


int main(int argc, char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
	//用ctrl+f5执行就不会一闪而过了
}
