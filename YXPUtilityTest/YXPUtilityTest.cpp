#ifdef _DEBUG
//for memory leak check
#define _CRTDBG_MAP_ALLOC //使生成的内存dump包含内存块分配的具体代码为止
#include <stdlib.h> 
#include <crtdbg.h>
#define CheckMemoryLeak _CrtSetDbgFlag( _CrtSetDbgFlag( _CRTDBG_REPORT_FLAG )| _CRTDBG_LEAK_CHECK_DF)
#endif 

#include <gtest/gtest.h>

int main(int argc, char* argv[])
{
	//第二步：在程序的入口处（就是main函数的开头(main函数内部)）写如下语句
#ifdef _DEBUG
	CheckMemoryLeak;
#endif
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
	//用ctrl+f5执行就不会一闪而过了
}
