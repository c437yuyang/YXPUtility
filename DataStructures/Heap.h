#include <algorithm>
#include <vector>
#include <functional>
namespace yxp_utility
{
	template<typename T, class Comp = std::greater<T>> //default is min heap
	class Heap
	{
	public:
		Heap() :heap_arr_() {}
		Heap(const std::vector<T> & v)
			: heap_arr_(v)
		{
			InitHeap();
		}

		Heap(const T*arr, size_t n)
			: heap_arr_(arr, arr + n)
		{
			InitHeap();
		}

		template<class T>
		void Push(const T& val)
		{
			heap_arr_.push_back(val);
			std::push_heap(heap_arr_.begin(), heap_arr_.end(), Comp());
		}

		T Pop()
		{
			std::pop_heap(heap_arr_.begin(), heap_arr_.end(), Comp());
			T back_save = heap_arr_.back();
			heap_arr_.pop_back();
			return back_save;
		}

		size_t size() { return heap_arr_.size(); }

	private:
		std::vector<T> heap_arr_;
		void InitHeap()
		{
			std::make_heap(heap_arr_.begin(), heap_arr_.end(), Comp());
		}
	};

}