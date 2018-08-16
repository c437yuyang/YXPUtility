#ifndef TRIETREE_H
#define TRIETREE_H
#include <stack>
namespace yxp_utility
{

	struct TrieNode
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
			/* TrieNode ** root = &(static_cast<TrieNode*>(root_)); */
			TrieNode ** root = &(root_);
			clearRoot(root);
		}

		void clear()
		{
			for (size_t i = 0; i < 26; ++i)
			{
				clearRoot(&(root_->nexts[i]));
			}
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
			clearInStack(wait2Delete);
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
		void add2Stack(TrieNode**root, std::stack<TrieNode**> &wait2Delete)
		{
			if (root == nullptr)
				return;
			wait2Delete.push(root);
			for (size_t i = 0; i < 26; ++i)
				if ((*root)->nexts[i] != nullptr)
					add2Stack(&(*root)->nexts[i], wait2Delete);
		}

		void clearInStack(std::stack<TrieNode**> &wait2Delete)
		{
			while (!wait2Delete.empty()) //全部清除掉
			{
				TrieNode** tmp = wait2Delete.top();
				wait2Delete.pop();
				delete [](*tmp)->nexts;
				(*tmp)->nexts = nullptr;
				delete *tmp;
				*tmp = nullptr;
			}
		}

		/// <summary>
		/// dfs清除内存
		/// </summary>
		void clearRoot(TrieNode ** root)
		{
			if ((*root) == nullptr)
				return;
			for (size_t i = 0; i < 26; ++i)
			{
				if ((*root)->nexts[i] != nullptr)
					clearRoot(&((*root)->nexts[i]));
			}
			delete[]((*root)->nexts);
			(*root)->nexts = nullptr;
			delete (*root);
			(*root) = nullptr;
		}

	private:
		TrieNode* root_; 
	};

}

#endif // !TRIETREE_H
