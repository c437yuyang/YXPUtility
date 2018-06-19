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


TEST(StrAlgoTest, SplitTest)
{
	std::string str1 = "1,2,3,45,-1,2";

	auto v = StrAlgo::split(str1, ',');
	std::vector<std::string> v_expect = { "1", "2", "3", "45", "-1", "2" };
	EXPECT_EQ(v, v_expect);

	v = StrAlgo::split(str1, ',');
	EXPECT_EQ(v, v_expect);

	str1 = "1,2,3,45,-1,2,"; //最后一个有也可以
	v = StrAlgo::split(str1, ',');
	EXPECT_EQ(v, v_expect);

	v = StrAlgo::split(str1, ',');
	EXPECT_EQ(v, v_expect);

	str1 = "1 2 3 45 -1 2 ";
	v = StrAlgo::split(str1, ' ');
	EXPECT_EQ(v, v_expect);

	//v = StrAlgo::Split2(str1, ' '); //split2不支持空格分割
	//EXPECT_EQ(v, v_expect);

	//测试空用例
	str1 = "";
	v_expect = {};
	v = StrAlgo::split(str1, ' ');
	EXPECT_EQ(v, v_expect);

	str1 = "12345";
	v_expect = {};
	v = StrAlgo::split(str1, ' ');
	EXPECT_EQ(v, v_expect);

}


TEST(StrAlgoTest, JoinTest)
{
	std::vector<std::string> test_strs = { "1", "2", "3", "-1" };

	auto res = StrAlgo::join(test_strs, '\0');
	std::string str_expect = "123-1";
	EXPECT_EQ(res, str_expect);


	res = StrAlgo::join(test_strs, ' ');
	str_expect = "1 2 3 -1";
	EXPECT_EQ(res, str_expect);
}

TEST(StrAlgoTest, JoinIfTest)
{
	std::vector<std::string> test_strs = { "1", "2", "13", "-1" };

	auto res = StrAlgo::joinIf(test_strs, '\0', [](const std::string&str) { return str.find("1") != -1; });
	std::string str_expect = "113-1";
	EXPECT_EQ(res, str_expect);


	res = StrAlgo::joinIf(test_strs, ' ', [](const std::string&str) { return str.find("1") != -1; });
	str_expect = "1 13 -1";
	EXPECT_EQ(res, str_expect);

	res = StrAlgo::joinIf(test_strs, ' ', [](const std::string&str) { return str.find("-") == -1; });
	str_expect = "1 2 13";
	EXPECT_EQ(res, str_expect);
}

TEST(StrAlgoTest, EndsWithTest)
{
	std::string str = "abcde";

	EXPECT_EQ(StrAlgo::endsWith(str, "de"), true);
	EXPECT_EQ(StrAlgo::endsWith(str, "de1"), false);
	EXPECT_EQ(StrAlgo::endsWith(str, "abcde"), true);
	EXPECT_EQ(StrAlgo::endsWith(str, "abcde1"), false);
}

TEST(StrAlgoTest, StartsWithTest)
{
	std::string str = "abcde";

	EXPECT_EQ(StrAlgo::startsWith(str, "ab"), true);
	EXPECT_EQ(StrAlgo::startsWith(str, "ab1"), false);
	EXPECT_EQ(StrAlgo::startsWith(str, "abcde"), true);
	EXPECT_EQ(StrAlgo::startsWith(str, "abcde1"), false);
}

TEST(StrAlgoTest, TrimStartTest)
{
	std::string str = "aaaabc";
	EXPECT_EQ(StrAlgo::trimStart(str, "a"), "bc");
	EXPECT_EQ(StrAlgo::trimStart(str, "aa"), "bc");
	EXPECT_EQ(StrAlgo::trimStart(str, "aaa"), "abc");
	EXPECT_EQ(StrAlgo::trimStart(str, "ab"), str);
	EXPECT_EQ(StrAlgo::trimStart(str, "abaaaaaaa"), str);
}

TEST(StrAlgoTest, TrimEndTest)
{
	std::string str = "bcdeeeee";
	EXPECT_EQ(StrAlgo::trimEnd(str, "e"), "bcd");
	EXPECT_EQ(StrAlgo::trimEnd(str, "ee"), "bcde");
	EXPECT_EQ(StrAlgo::trimEnd(str, "ab"), str);
	EXPECT_EQ(StrAlgo::trimEnd(str, "abaaaaaaa"), str);
}

TEST(StrAlgoTest, TrimTest)
{
	std::string str = "eeebcdeeeee";
	EXPECT_EQ(StrAlgo::trim(str, "e"), "bcd");
}

TEST(StrAlgoTest, ReplaceAllTest)
{
	std::string str = "bcdeeee";
	EXPECT_EQ(StrAlgo::replaceAll(str, "e", "1"), "bcd1111");
	EXPECT_EQ(StrAlgo::replaceAll(str, "e", "22"), "bcd22222222");
	EXPECT_EQ(StrAlgo::replaceAll(str, "ee", "1"), "bcd11");
	EXPECT_EQ(StrAlgo::replaceAll(str, "ee", ""), "bcd");
	EXPECT_EQ(StrAlgo::replaceAll(str, "aee", "1"), str);
}
TEST(StrAlgoTest, ReplaceFirstTest)
{
	std::string str = "bcdeeee";
	EXPECT_EQ(StrAlgo::replaceFirst(str, "e", "1"), "bcd1eee");
	EXPECT_EQ(StrAlgo::replaceFirst(str, "e", "11"), "bcd11eee");
	EXPECT_EQ(StrAlgo::replaceFirst(str, "ea", "11"), str);
}

TEST(StrAlgoTest, EraseAllTest)
{
	std::string str = "bcdeeee";
	EXPECT_EQ(StrAlgo::eraseAll(str, "e"), "bcd");
}


int main(int argc, char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
	//用ctrl+f5执行就不会一闪而过了
}
