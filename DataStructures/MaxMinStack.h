#ifndef _MAXMINSTACK_H_
#define _MAXMINSTACK_H_
#include <stack>
#include <algorithm>
#include <functional>
#include <stdexcept>
namespace yxp_utility
{
	template<class T, class Comp = std::less<T> >
	class MaxMinStack
	{
	public:
		MaxMinStack() = default;
		void push(const T&val)
		{
			data_stack_.push(val);
			if (max_min_stack_.empty())
				max_min_stack_.push(val);
			else
			{
				//if (val > max_min_stack_.top())
				if (Comp()(val, max_min_stack_.top()))
					max_min_stack_.push(val);
				else
					max_min_stack_.push(max_min_stack_.top());
			}
		}

		T pop()
		{
			if (data_stack_.empty())
				throw std::runtime_error("Empty Stack!!!");

			T& top_val = data_stack_.top();
			data_stack_.pop();
			max_min_stack_.pop();
			return top_val;
		}

		T& top()
		{
			if (data_stack_.empty())
				throw std::runtime_error("Empty Stack!!!");
			return data_stack_.top();
		}

		T maxOrMin()
		{
			if (data_stack_.empty())
				throw std::runtime_error("Empty Stack!!!");
			return max_min_stack_.top();
		}

		bool empty()
		{
			return data_stack_.empty();
		}

		size_t size()
		{
			return data_stack_.size();
		}

	private:
		std::stack<T> data_stack_;
		std::stack<T> max_min_stack_;
	};
}
#endif
