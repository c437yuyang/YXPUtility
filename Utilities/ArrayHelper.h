#ifndef ARRAYHELPER_H
#define ARRAYHELPER_H

#include <vector>
#include <iostream>
#include <algorithm>

#define ARRSIZE(arr) (sizeof(arr)/sizeof(arr[0]))

namespace yxp_utility
{
	class ArrayHelper
	{
	public:
		template<class T>
		inline static void printArr(const T*arr, size_t n, char delimeter = ' ', bool endWithNewLine = true)
		{
			for (size_t i = 0; i != n; ++i)
				std::cout << arr[i] << delimeter;
			if (endWithNewLine)
				std::cout << std::endl;
		}

		template<class T>
		inline static void printArr(const std::vector<T> &arr, char delimeter = ' ', bool endWithNewLine = true)
		{
			std::for_each(arr.begin(), arr.end(), [delimeter](const T&val) { std::cout << val << delimeter; });
			if (endWithNewLine)
				std::cout << std::endl;
		}

		template<class T>
		inline static void printMatrix(const std::vector<std::vector<T>> &mat, char delimeter = ' ')
		{
			std::for_each(mat.begin(), mat.end(), [delimeter](const std::vector<T>&v) { printArr(v, delimeter, true); });
		}

		template<class T>
		inline static void printMatrix(const T* mat, size_t rows, size_t cols, char delimeter = ' ', bool endWithNewLine = true)
		{
			//std::for_each(mat, mat + rows, [delimeter, cols](const T*arr) { printArr(arr, cols, delimeter, true); });
			for (size_t i = 0; i < rows; ++i)
			{
				for (size_t j = 0; j < cols; ++j)
					std::cout << mat[i*cols + j] << delimeter;
				std::cout << std::endl;
			}
			if (endWithNewLine)
				std::cout << std::endl;
		}

		/// <summary>
		/// 不改变其他元素先后顺序交换元素,比如1234,交换2和4,直接交换后是1432就乱了，这个交换后就是1423
		/// 这个和直接交换的区别，在getPermutation(3,3)的时候，最后两个顺序会有区别
		/// 从前往后移动,要求i<j
		/// </summary>
		template<class T>
		void keepOrderSwap1(std::vector<T>&arr, size_t i, size_t j)
		{
			assert(i <= j);
			char tmp = arr[j];
			for (size_t i1 = j; i1 > i; --i1) //递减不带=号是可以用size_t的
				arr[i1] = arr[i1 - 1];
			arr[i] = tmp;
		}

		//从后往前移动
		template<class T>
		void keepOrderSwap2(std::vector<T>&arr, size_t i, size_t j)
		{
			assert(i <= j);
			char tmp = arr[i];
			for (size_t i1 = i; i1 < j; ++i1)
				arr[i1] = arr[i1 + 1];
			arr[j] = tmp;
		}

	};
}

#endif