#include <gtest/gtest.h>
#include "Utilities/RandomHelper.h"
#include "Utilities/ArrayHelper.h"
using namespace yxp_utility;

TEST(RandomHelperTest, demo1)
{
	yxp_utility::RandomHelper::initSeed();
	auto v = yxp_utility::RandomHelper::randomMatrix(5, 5, -10, 10);
	/*yxp_utility::ArrayHelper::printMatrix(v);*/
	int *p = new int[5 * 5];
	yxp_utility::RandomHelper::randomMatrix(p, 5, 5, -10, 10);
	/*yxp_utility::ArrayHelper::printMatrix(p, 5, 5);*/
	assert(v.size() == 5);
	delete[]p;
	p = nullptr;
}