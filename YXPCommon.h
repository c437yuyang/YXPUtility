#include <iostream>
#include <fstream>
#include <random>
#include <vector>
#include <ctime>
#include <cassert>


#define ARRSIZE(arr) (sizeof(arr)/sizeof(arr[0]))

namespace yxp_utility
{
	template<typename T, class Comp = std::greater<T>> //default is min heap
	class Heap
	{
	public:
		Heap() :heap_arr_() {}
		Heap(const std::vector<T> & v)
			: heap_arr_(v), InitHeap()
		{
		}

		Heap(const T*arr, size_t n)
			: heap_arr_(arr, arr + n), InitHeap()
		{
		}

		template<class T>
		void Push(const T& val)
		{
			heap.push_back(val);
			std::push_heap(heap_arr_.begin(), heap_arr_.end(), Comp);
		}

		T Pop()
		{
			std::pop_heap(heap_arr_.begin(), heap_arr_.end(), SmallHeap);
			T back_save = heap.back();
			heap.pop_back();
			return back_save;
		}

	private:
		std::vector<T> heap_arr_;
		void InitHeap()
		{
			std::make_heap(heap_arr_.begin(), heap_arr_.end(), Comp);
		}

	};

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
			size_t n = arr.size();
			for (size_t i = 0; i != n; ++i)
				std::cout << arr[i] << delimeter;
			if (endWithNewLine)
				std::cout << std::endl;
		}
	};

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
			return rand() % (max - min) + min; //用C++11的随机数返回的是[1-int_max],反而不好处理
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
			for (int i = 0; i != size; ++i)
				arr[i] = randomInt(min, max);
		}

		inline static std::vector<int> randomArray(size_t size, int min, int max)
		{
			std::vector<int> res;
			randomArray(res, size, min, max);
			return res;
		}

		template<class T>
		inline static void copyArray(T *dst, const T *src, size_t size)
		{
			memcpy(dst, src, size * sizeof(T));
		}
	private:
		static bool seed_set_;
	};
	bool RandomHelper::seed_set_ = false;


}
