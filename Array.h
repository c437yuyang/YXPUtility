#pragma once
#include <iostream>
using std::ostream;

namespace yxp_utility {

	//1维数组
	template <class T>
	struct _1dArray {
		_1dArray(int n) :size(n) { elem = new T[n](); } //默认初始化
		T& operator[](int i)
		{
			if (i > size - 1 || i < 0)
				throw std::out_of_range("下标出错");
			return elem[i];
		}

		const T& operator[](int i) const 
		{
			if (i > size - 1 || i < 0)
				throw std::out_of_range("下标出错");
			return elem[i];
		}

		~_1dArray() { delete[] elem; elem = 0; }
		
		_1dArray& operator=(const _1dArray<T>& rhs) 
		{
			if (elem != NULL) delete[] elem;
			elem = new T[rhs.size];
			memcpy(elem, rhs.elem, sizeof(T)*rhs.size);
			size = rhs.size;
			return *this;
		}

		_1dArray(const _1dArray<T>& rhs) 
		{
			//if (elem != NULL) delete[] elem;
			elem = new T[rhs.size];
			memcpy(elem, rhs.elem, sizeof(T)*rhs.size);
			size = rhs.size;
		}

		T* elem; //这个类不考虑封装
		int size;

	};

	//重载输出运算符
	template<class T>
	ostream& operator<<(ostream& out, const _1dArray<T>& arr)
	{
		for (int j = 0; j != arr.size; ++j)
		{
			out << arr[j] << " ";
		}
		out << endl;
		return out;
	}

	//2维数组，提供两个版本，这个版本内部用二维数组，方便[][]操作
#pragma region 内部二维数组实现版本
	//template <class T>
	//struct _2dArray {
	//	_2dArray(int m, int n) :rows(m), cols(n)
	//	{
	//		elem = new T*[m];
	//		for (int i = 0; i != m; ++i)
	//		{
	//			elem[i] = new T[n](); //默认初始化 
	//		}
	//	}
	//	T* operator[](int i) { return elem[i]; }
	//	const T* operator[](int i) const { return elem[i]; }
	//	~_2dArray()
	//	{
	//		for (int i = 0; i != rows; ++i)
	//		{
	//			delete[] elem[i];
	//		}
	//		delete[]elem;
	//		elem = 0;
	//	}
	//	T** elem;
	//	int rows;
	//	int cols;
	//};


	//template<class T>
	//ostream& operator<<(ostream& out, const _2dArray<T>& mat)
	//{
	//	for (int i = 0; i != mat.rows; ++i)
	//	{
	//		for (int j = 0; j != mat.cols; ++j)
	//		{
	//			out << mat[i][j] << " ";
	//		}
	//		out << endl;
	//	}
	//	return out;
	//}
#pragma endregion

	template <class T>
	struct _2dArray {
		_2dArray(int m, int n) :rows(m), cols(n)
		{
			elem = new T[m*n]();
		}
		T* operator[](int i) { return &elem[i*cols]; } //但是这种方法还是没法检查两个参数的合法性，其实也不用自己检查，自己检查也就是抛个异常，反正你越界，系统也会抛出异常
		const T* operator[](int i) const { return &elem[i*cols]; }
		~_2dArray()
		{
			delete[]elem;
			elem = 0;
		}

		_2dArray& operator=(const _2dArray<T>& rhs)
		{
			if (elem != NULL) delete[] elem;
			elem = new T[rhs.rows*rhs.cols];
			memcpy(elem, rhs.elem, sizeof(T)*rhs.rows*rhs.cols);
			rows = rhs.rows;
			cols = rhs.cols;
			return *this;
		}

		_2dArray(const _2dArray<T>& rhs)
		{
			//if (elem != NULL) delete[] elem;
			elem = new T[rhs.rows*rhs.cols];
			memcpy(elem, rhs.elem, sizeof(T)*rhs.rows*rhs.cols);
			rows = rhs.rows;
			cols = rhs.cols;
		}


		T* elem;
		int rows;
		int cols;
	};


	template<class T>
	ostream& operator<<(ostream& out, const _2dArray<T>& mat)
	{
		for (int i = 0; i != mat.rows; ++i)
		{
			for (int j = 0; j != mat.cols; ++j)
			{
				out << mat[i][j] << " ";
			}
			out << endl;
		}
		return out;
	}


}

