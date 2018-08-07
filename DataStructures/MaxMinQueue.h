#ifndef _MAXMINQUEUE_H_
#define _MAXMINQUEUE_H_
#include "MaxMinStack.h"
#include <stdexcept>
namespace yxp_utility
{
	template<class T, class Comp = std::less<T> >
	class MaxMinQueue
	{
	public:
		MaxMinQueue() = default;
		void push(const T&val)
		{
			push_stack_.push(val);
		}

		T pop()
		{
			moveBetweenStack();
			return pop_stack_.pop();
		}

		T& top()
		{
			moveBetweenStack();
			return pop_stack_.top();
		}

		T maxOrMin()
		{
			moveBetweenStack();
			if (!push_stack_.empty())
				return std::max(push_stack_.maxOrMin(), pop_stack_.maxOrMin());
			else
				return pop_stack_.maxOrMin();
		}

		bool empty()
		{
			return push_stack_.empty() && pop_stack_.empty();
		}

		size_t size()
		{
			return push_stack_.size() + pop_stack_.size();
		}

	private:
		void moveBetweenStack()
		{
			if (pop_stack_.empty())
			{
				if (push_stack_.empty())
					throw std::runtime_error("empty stack!!!");
				while (!push_stack_.empty())
					pop_stack_.push(push_stack_.pop());
			}
		}

	private:
		MaxMinStack<T, Comp> push_stack_;
		MaxMinStack<T, Comp> pop_stack_;
	};
}
#endif
