#include <gtest/gtest.h>
#include "DataStructures/FifoSet.h"
using namespace yxp_utility;

TEST(FifoSetTest, demo1) {
	FifoSet<int> fifoset;
	fifoset.insert(0);
	fifoset.insert(1);
	fifoset.insert(1);
	fifoset.insert(2);
	fifoset.insert(3);

	EXPECT_EQ(fifoset.contains(1), true);
	EXPECT_EQ(fifoset.find(0) - fifoset.begin(), 0);
	EXPECT_EQ(fifoset.find(1) - fifoset.begin(), 1);
	EXPECT_EQ(*fifoset.find(1), 1);
	EXPECT_EQ(*fifoset.find(2), 2);
	EXPECT_EQ(*fifoset.find(3), 3);
	fifoset.erase(1);
	EXPECT_EQ(fifoset.find(0) - fifoset.begin(), 0);
	EXPECT_EQ(fifoset.find(1), fifoset.end());
	EXPECT_EQ(fifoset.find(2) - fifoset.begin(), 1);
	EXPECT_EQ(fifoset.find(3) - fifoset.begin(), 2);
}