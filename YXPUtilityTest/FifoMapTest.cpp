#include <gtest/gtest.h>
#include "DataStructures/FifoMap.h"
#include <string>
using namespace yxp_utility;

TEST(FifoMapTest, demo1) {
	FifoMap<int, std::string> fifomap;
	fifomap.insert(0, "0");
	fifomap.insert(1, "1");
	fifomap.insert(1, "1");
	fifomap.insert(2, "2");
	fifomap.insert(3, "3");

	EXPECT_EQ(fifomap.contains(1), true);
	EXPECT_EQ(fifomap.find(0) - fifomap.begin(), 0);
	EXPECT_EQ(fifomap.find(1) - fifomap.begin(), 1);
	EXPECT_EQ((fifomap.find(1))->second, "1");
	EXPECT_EQ((fifomap.find(2))->second, "2");
	EXPECT_EQ((fifomap.find(3))->second, "3");

	fifomap.erase(1);
	EXPECT_EQ(fifomap.find(0) - fifomap.begin(), 0);
	EXPECT_EQ(fifomap.find(1), fifomap.end());
	EXPECT_EQ(fifomap.find(2) - fifomap.begin(), 1);
	EXPECT_EQ(fifomap.find(3) - fifomap.begin(), 2);
}