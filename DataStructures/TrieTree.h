#ifndef TRIETREE_H
#define TRIETREE_H
#include <stack>
namespace yxp_utility
{

	struct  TrieNode
	{
	public:
		int path; //经过这个节点的路径数目
		int end; //这个节点结尾的路径数目
		TrieNode **nexts;

		TrieNode() :path(0), end(0), nexts(new TrieNode*[26])
		{
			for (size_t i = 0; i < 26; ++i)
				nexts[i] = nullptr;//每个节点，都有所有可能的26条路径
		}
	};

	class TrieTree
	{
	public:
		TrieTree() :root_(new TrieNode()) {}

		~TrieTree()
		{

		}

		void insert(const std::string&str)
		{
			if (str == "")
				return;
			TrieNode * node = root_;
			for (size_t i = 0; i < str.length(); ++i)
			{
				size_t idx = str[i] - 'a';
				if (node->nexts[idx] == nullptr)
					node->nexts[idx] = new TrieNode();
				node = node->nexts[idx];
				++node->path;
			}
			++node->end;
		}

		void remove(const std::string&str) 
		{
			if (count(str) == 0)
				return;
			std::stack<TrieNode**> wait2Delete; //因为指针是拷贝的，所以要传二级指针
			TrieNode * node = root_; //下面是一定找得到了
			for (size_t i = 0; i < str.length(); ++i)
			{
				size_t idx = str[i] - 'a';
				if (--node->nexts[idx]->path == 0)
					wait2Delete.push(&(node->nexts[idx]));
				node = node->nexts[idx];
			}
			--node->end;
			while (!wait2Delete.empty()) //全部清除掉
			{
				TrieNode** tmp = wait2Delete.top();
				wait2Delete.pop();
				delete *tmp;
				*tmp = nullptr;
			}
		}


		size_t count(const std::string &str) const
		{
			if (str == "")
				return 0;
			TrieNode * node = root_;
			for (size_t i = 0; i < str.length(); ++i)
			{
				size_t idx = str[i] - 'a';
				if (node->nexts[idx] == nullptr)
					return 0;
				node = node->nexts[idx];
			}
			return node->end;
		}

		size_t prefixCount(const std::string&str) const
		{
			if (str == "")
				return 0;
			TrieNode * node = root_;
			for (size_t i = 0; i < str.length(); ++i)
			{
				size_t idx = str[i] - 'a';
				if (node->nexts[idx] == nullptr)
					return 0;
				node = node->nexts[idx];
			}
			return node->path;
		}

	private:
		 TrieNode* const root_; //不允许改变，只能在构造函数初始化
	};

}

#endif // !TRIETREE_H
