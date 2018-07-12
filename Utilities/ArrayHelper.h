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
		/// ���ı�����Ԫ���Ⱥ�˳�򽻻�Ԫ��,����1234,����2��4,ֱ�ӽ�������1432�����ˣ�������������1423
		/// �����ֱ�ӽ�����������getPermutation(3,3)��ʱ���������˳���������
		/// ��ǰ�����ƶ�,Ҫ��i<j
		/// </summary>
		template<class T>
		void keepOrderSwap1(std::vector<T>&arr, size_t i, size_t j)
		{
			assert(i <= j);
			char tmp = arr[j];
			for (size_t i1 = j; i1 > i; --i1) //�ݼ�����=���ǿ�����size_t��
				arr[i1] = arr[i1 - 1];
			arr[i] = tmp;
		}

		//�Ӻ���ǰ�ƶ�
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