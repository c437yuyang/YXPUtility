#include <gtest/gtest.h>
#include "Utilities/StrAlgo.h"
using namespace yxp_utility;


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

	str = "   eeebcdeeeee   ";
	EXPECT_EQ(StrAlgo::trim(str), "eeebcdeeeee");

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