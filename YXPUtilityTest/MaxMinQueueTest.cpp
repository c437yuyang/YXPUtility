#include <gtest/gtest.h>
#include "DataStructures/MaxMinQueue.h"
using namespace yxp_utility;

TEST(MaxMinQueueTest, demo1)
{
	MaxMinQueue<int, std::greater<int>> maxQueue;

	maxQueue.push(5);
	maxQueue.push(4);
	maxQueue.push(6);
	maxQueue.push(3);

	EXPECT_EQ(maxQueue.max(), 6);
	EXPECT_EQ(maxQueue.pop(), 5);
	EXPECT_EQ(maxQueue.max(), 6);
	EXPECT_EQ(maxQueue.top(), 4);
	EXPECT_EQ(maxQueue.pop(), 4);
	EXPECT_EQ(maxQueue.max(), 6);
	EXPECT_EQ(maxQueue.pop(), 6);
	EXPECT_EQ(maxQueue.max(), 3);
	EXPECT_EQ(maxQueue.pop(), 3);

}