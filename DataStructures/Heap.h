#ifndef HEAP_H
#define HEAP_H

#include <algorithm>
#include <vector>
#include <functional>
namespace yxp_utility
{
	template<typename T, class Comp = std::greater<T> > //default is min heap
	class Heap
	{
	public:
		Heap() :heap_arr_() {}
		Heap(const std::vector<T> & v)
			: heap_arr_(v)
		{
			initHeap();
		}

		Heap(const T*arr, size_t n)
			: heap_arr_(arr, arr + n)
		{
			initHeap();
		}

		template<typename tp>
		void push(const tp& val)
		{
			heap_arr_.push_back(val);
			std::push_heap(heap_arr_.begin(), heap_arr_.end(), Comp());
		}

		T pop()
		{
			std::pop_heap(heap_arr_.begin(), heap_arr_.end(), Comp());
			T back_save = heap_arr_.back();
			heap_arr_.pop_back();
			return back_save;
		}

		size_t size() { return heap_arr_.size(); }
		bool empty() { return heap_arr_.empty(); }
	private:
		std::vector<T> heap_arr_;
		void initHeap()
		{
			std::make_heap(heap_arr_.begin(), heap_arr_.end(), Comp());
		}
	};

}

#endif
