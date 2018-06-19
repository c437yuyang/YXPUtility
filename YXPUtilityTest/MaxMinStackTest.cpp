#include <gtest/gtest.h>
#include "DataStructures/MaxMinStack.h"

using namespace yxp_utility;

TEST(MaxMinStackTest, demo1)
{
	MaxMinStack<int> minStack;
	minStack.push(1);
	minStack.push(4);

	EXPECT_EQ(minStack.maxOrMin(), 1);
	EXPECT_EQ(minStack.top(), 4);
	EXPECT_EQ(minStack.pop(), 4);
	EXPECT_EQ(minStack.maxOrMin(), 1);
	EXPECT_EQ(minStack.top(), 1);
	EXPECT_EQ(minStack.pop(), 1);
	EXPECT_EQ(minStack.empty(), true);
	EXPECT_EQ(minStack.size(), 0);
	minStack.push(10);
	minStack.push(3);
	EXPECT_EQ(minStack.maxOrMin(), 3);
	EXPECT_EQ(minStack.top(), 3);
	EXPECT_EQ(minStack.pop(), 3);
	EXPECT_EQ(minStack.maxOrMin(), 10);
}

TEST(MaxMinStackTest, demo2)
{
	MaxMinStack<int, std::greater<int>> maxStack;
	maxStack.push(4);
	maxStack.push(1);

	EXPECT_EQ(maxStack.maxOrMin(), 4);
	EXPECT_EQ(maxStack.top(), 1);
	EXPECT_EQ(maxStack.pop(), 1);
	EXPECT_EQ(maxStack.maxOrMin(), 4);
	EXPECT_EQ(maxStack.top(), 4);
	EXPECT_EQ(maxStack.pop(), 4);
	EXPECT_EQ(maxStack.empty(), true);
	EXPECT_EQ(maxStack.size(), 0);
	maxStack.push(10);
	maxStack.push(3);
	EXPECT_EQ(maxStack.maxOrMin(), 10);
	EXPECT_EQ(maxStack.top(), 3);
	EXPECT_EQ(maxStack.pop(), 3);
	EXPECT_EQ(maxStack.maxOrMin(), 10);
}