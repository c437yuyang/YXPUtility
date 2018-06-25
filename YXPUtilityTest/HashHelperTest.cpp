#include <gtest/gtest.h>
#include "Utilities/HashHelper.h"
#include <unordered_set>
using namespace yxp_utility;

class Widget
{
public:
	int data;
	Widget(int i) : data(i) {}
	Widget(const Widget &other) : data(other.data) { std::cout << "copy ctor" << std::endl; }
};


TEST(HashHelperTest, PtrHasherTest)
{
	Widget w1(10), w2(11), w3(12);
	std::unordered_set<Widget*, PtrHasher<Widget*>> set; //不用实现std::equal_to了，指针可以用std::equal_to<T*>
	set.insert(&w1);
	set.insert(&w2);
	EXPECT_NE(set.find(&w1), set.end());
	EXPECT_NE(set.find(&w2), set.end());
	EXPECT_EQ(set.find(&w3), set.end());
}

class Widget_Complex
{
public:
	Widget_Complex(int i, int i1, std::string str) : data(i), data1(i1), str_data_(str) {}
	bool operator==(const Widget_Complex &rhs) const
	{
		return rhs.data == data &&
			rhs.data1 == data1 &&
			rhs.str_data_ == str_data_;
	}
	int data;
	int data1;
	std::string str_data_;
};

//需要自己声明一个调用类
class Widget_ComplexHasher
{
public:
	size_t operator()(const Widget_Complex &cw) const
	{
		return HashHelper::hash_val(cw.data, cw.data1, cw.str_data_); //这里传入每个成员即可
	}
};

TEST(HashHelperTest, HashHelperTest1)
{
	std::unordered_set<Widget_Complex, Widget_ComplexHasher> cw_hash_set;
	cw_hash_set.insert(Widget_Complex(1, 1, "2"));
	cw_hash_set.insert(Widget_Complex(1, 2, "3"));
	EXPECT_NE(cw_hash_set.find(Widget_Complex(1, 1, "2")), cw_hash_set.end());
	EXPECT_NE(cw_hash_set.find(Widget_Complex(1, 2, "3")), cw_hash_set.end());
	EXPECT_EQ(cw_hash_set.find(Widget_Complex(1, 2, "2")), cw_hash_set.end());
}
