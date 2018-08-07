#ifndef RANDOMHELPER_H
#define RANDOMHELPER_H

#include <random>
#include <vector>
#include <ctime>
#include <cassert>
#include <functional>

namespace yxp_utility
{
	class RandomHelper
	{
	public:
		/************************************************************************/
		/* must call this function before use random numeric functions			*/
		/************************************************************************/
		inline static void initSeed()
		{
			std::srand(static_cast<unsigned int>(::time(nullptr)));
			//srand((unsigned int)(time(NULL)));
			seed_set_ = true;
		}


		/*
		return a random integer between [m,n)
		*/
		inline static int randomInt(int min, int max)
		{
			assert(seed_set_);
			assert(min <= max);
			//rand() return [0-RAND_MAX]
			return rand() % (max - min) + min; //��C++11����������ص���[1-int_max],�������ô���
		}

		/*
		return a random float number between [0-1]
		*/
		inline static double randomDouble()
		{
			assert(seed_set_);
			return rand() / double(RAND_MAX);
		}

		/*
		return a random float number with digit fraction part
		*/
		inline static double rand0to1(int digit = 3)
		{
			int coef = static_cast<int>((10, digit));
			return rand() % coef / double(coef);
		}

		/*
		get random integer array,do not allocate memory
		*/
		inline static void randomArray(int *arr, size_t size, int min, int max)
		{
			assert(arr != nullptr);
			for (size_t i = 0; i != size; ++i)
				arr[i] = randomInt(min, max);
		}

		/*
		get random integer vector, will clear the input vector
		*/
		inline static void randomArray(std::vector<int>& arr, size_t size, int min, int max)
		{
			arr.clear();
			arr.resize(size);
			for (size_t i = 0; i != size; ++i)
				arr[i] = randomInt(min, max);
		}

		/*
		get random integer vector
		*/
		inline static std::vector<int> randomArray(size_t size, int min, int max)
		{
			std::vector<int> res;
			randomArray(res, size, min, max);
			return res;
		}


		/*
		get random integer matrix using 1D Array,do not allocate memory
		*/
		inline static void randomMatrix(int * mat, size_t rows, size_t cols, int min, int max)
		{
			assert(mat != nullptr && rows > 0 && cols > 0);
			for (size_t i = 0; i < rows; ++i)
				for (size_t j = 0; j < cols; ++j)
					mat[i*cols + j] = randomInt(min, max);
		}


		/*
		get random integer matrix using std::vector<std::vector<int>>
		*/
		inline static std::vector<std::vector<int>> randomMatrix(size_t rows, size_t cols, int min, int max)
		{
			assert(rows > 0 && cols > 0);
			std::vector<std::vector<int>> res;
			res.reserve(rows);
			//std::for_each(res.begin(), res.end(), [cols](std::vector<int>&v) { v.reserve(cols); });
			for (size_t i = 0; i < rows; ++i)
				res.push_back(std::move(randomArray(cols, min, max)));
			return res;
		}

		template<class T>
		inline static void copyArray(T *dst, const T *src, size_t size)
		{
			memcpy(dst, src, size * sizeof(T));
		}

		static bool sortCheck(int nSize, int nTestTime, int min, int max, void(*pSort)(int *, int))
		{
			int *pTestArr1 = new int[nSize];
			int *pTestArr2 = new int[nSize];
			initSeed();
			for (int i = 0; i != nTestTime; ++i)
			{
				randomArray(pTestArr1, nSize, min, max); //�������������
				//randomArray(pTestArr1, nSize, 1000, 9999); //radix_sortר�ã����贫������3λ��
				memcpy(pTestArr2, pTestArr1, nSize * sizeof(int));
				pSort(pTestArr1, nSize);
				std::sort(pTestArr2, pTestArr2 + nSize);
				memcpy(pTestArr1, pTestArr2, nSize * sizeof(int));
				if (memcmp(pTestArr1, pTestArr2, nSize * sizeof(int) != 0))
					return false;
			}
			delete[] pTestArr1;
			delete[] pTestArr2;
			return true;
		}


	private:
		static bool seed_set_;
	};
	bool RandomHelper::seed_set_ = false;
}
#endif
