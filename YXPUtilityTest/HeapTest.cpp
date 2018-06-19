#include <gtest/gtest.h>
#include "DataStructures/Heap.h"
using namespace yxp_utility;

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