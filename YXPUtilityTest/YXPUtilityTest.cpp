#include <gtest/gtest.h>

int main(int argc, char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
	//用ctrl+f5执行就不会一闪而过了
}
