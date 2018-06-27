#ifndef ARRAY_H
#define ARRAY_H
#include <iostream>
#include <stdexcept>
using std::ostream;

namespace yxp_utility
{

	//1ά����
	template <class T>
	struct Array1D
	{
		Array1D(size_t n) :size_(n) { elem_ = new T[n](); } //Ĭ�ϳ�ʼ��
		T& operator[](size_t idx)
		{
			if (idx > size_ - 1 || idx < 0)
				throw std::out_of_range("index error");
			return elem_[idx];
		}

		const T& operator[](size_t idx) const
		{
			if (idx > size_ - 1 || idx < 0)
				throw std::out_of_range("index error");
			return elem_[idx];
		}

		~Array1D() { delete[] elem_; elem_ = 0; }

		Array1D& operator=(const Array1D<T>& rhs)
		{
			if (this == &rhs)
				return *this;
			if (elem_ != nullptr) delete[] elem_;
			elem_ = new T[rhs.size_];
			memcpy(elem_, rhs.elem_, sizeof(T)*rhs.size_);
			size_ = rhs.size_;
			return *this;
		}

		Array1D(const Array1D<T>& rhs)
		{
			elem_ = new T[rhs.size_];
			memcpy(elem_, rhs.elem_, sizeof(T)*rhs.size_);
			size_ = rhs.size_;
		}

		T* elem_; //����಻���Ƿ�װ
		size_t size_;
	};

	//������������
	template<class T>
	ostream& operator<<(ostream& out, const Array1D<T>& arr)
	{
		for (int j = 0; j != arr.size_; ++j)
			out << arr[j] << " ";
		out << std::endl;
		return out;
	}

	//2ά���飬�ṩ�����汾������汾�ڲ��ö�ά���飬����[][]����
#pragma region �ڲ���ά����ʵ�ְ汾
	//template <class T>
	//struct Array2D {
	//	Array2D(int m, int n) :rows(m), cols(n)
	//	{
	//		elem = new T*[m];
	//		for (int i = 0; i != m; ++i)
	//		{
	//			elem[i] = new T[n](); //Ĭ�ϳ�ʼ�� 
	//		}
	//	}
	//	T* operator[](int i) { return elem[i]; }
	//	const T* operator[](int i) const { return elem[i]; }
	//	~Array2D()
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
	//ostream& operator<<(ostream& out, const Array2D<T>& mat)
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

	//һά����ʵ�ְ汾
	template <class T>
	struct Array2D
	{
		Array2D(int m, int n) :rows_(m), cols_(n)
		{
			elem_ = new T[m*n]();
		}
		T* operator[](int i) { return &elem_[i*cols_]; } //�������ַ�������û��������������ĺϷ��ԣ���ʵҲ�����Լ���飬�Լ����Ҳ�����׸��쳣��������Խ�磬ϵͳҲ���׳��쳣
		const T* operator[](int i) const { return &elem_[i*cols_]; }
		~Array2D()
		{
			delete[]elem_;
			elem_ = 0;
		}

		Array2D& operator=(const Array2D<T>& rhs)
		{
			if (elem_ != nullptr) delete[] elem_;
			elem_ = new T[rhs.rows_*rhs.cols_];
			memcpy(elem_, rhs.elem_, sizeof(T)*rhs.rows_*rhs.cols_);
			rows_ = rhs.rows_;
			cols_ = rhs.cols_;
			return *this;
		}

		Array2D(const Array2D<T>& rhs)
		{
			//if (elem != NULL) delete[] elem;
			elem_ = new T[rhs.rows_*rhs.cols_];
			memcpy(elem_, rhs.elem_, sizeof(T)*rhs.rows_*rhs.cols_);
			rows_ = rhs.rows_;
			cols_ = rhs.cols_;
		}


		T* elem_;
		size_t rows_;
		size_t cols_;
	};


	template<class T>
	ostream& operator<<(ostream& out, const Array2D<T>& mat)
	{
		for (size_t i = 0; i != mat.rows_; ++i)
		{
			for (size_t j = 0; j != mat.cols_; ++j)
				out << mat[i][j] << " ";
			out << std::endl;
		}
		return out;
	}
}

#endif
