#include <gtest/gtest.h>
#include "Utilities/CLibs_Impl.h"
TEST(CLibs_ImplTest, strlenTest)
{
	EXPECT_EQ(yxp_utility::strlen("abc"), 3);
	EXPECT_EQ(yxp_utility::strlen("a"), 1);
	EXPECT_EQ(yxp_utility::strlen(""), 0);
}


TEST(CLibs_ImplTest, strmpTest)
{
	EXPECT_EQ(yxp_utility::strcmp("", ""), 0);
	EXPECT_LT(yxp_utility::strcmp("abc", "bcde"), 0);
	EXPECT_GT(yxp_utility::strcmp("abc", "Acde"), 0);
	EXPECT_EQ(yxp_utility::strcmp("abc", "abc"), 0);
}