#ifndef TRIETREE_H
#define TRIETREE_H
#include <stack>
namespace yxp_utility
{
	template<size_t nextcnt = 26>
	struct TrieNode
	{
	public:
		int path; //��������ڵ��·����Ŀ
		int end; //����ڵ��β��·����Ŀ
		TrieNode<nextcnt> **nexts;

		TrieNode<nextcnt>() :path(0), end(0), nexts(new TrieNode<nextcnt>*[nextcnt])
		{
			for (size_t i = 0; i < nextcnt; ++i)
				nexts[i] = nullptr;//ÿ���ڵ㣬�������п��ܵ�26��·��
		}
	};

	template<size_t nextcnt = 26>
	class TrieTree
	{
	public:
		TrieTree(char start) :root_(new TrieNode<nextcnt>()),startValue_(start) {}

		~TrieTree()
		{
			/* TrieNode<nextcnt> ** root = &(static_cast<TrieNode<nextcnt>*>(root_)); */
			TrieNode<nextcnt> ** root = &(root_);
			clearRoot(root);
		}

		void clear()
		{
			for (size_t i = 0; i < nextcnt; ++i)
			{
				clearRoot(&(root_->nexts[i]));
			}
		}

		void insert(const std::string&str)
		{
			if (str == "")
				return;
			TrieNode<nextcnt> * node = root_;
			for (size_t i = 0; i < str.length(); ++i)
			{
				size_t idx = str[i] - startValue_;
				if (node->nexts[idx] == nullptr)
					node->nexts[idx] = new TrieNode<nextcnt>();
				node = node->nexts[idx];
				++node->path;
			}
			++node->end;
		}

		void remove(const std::string&str)
		{
			if (count(str) == 0)
				return;
			std::stack<TrieNode<nextcnt>**> wait2Delete; //��Ϊָ���ǿ����ģ�����Ҫ������ָ��
			TrieNode<nextcnt> * node = root_; //������һ���ҵõ���
			for (size_t i = 0; i < str.length(); ++i)
			{
				size_t idx = str[i] - startValue_;
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
			TrieNode<nextcnt> * node = root_;
			for (size_t i = 0; i < str.length(); ++i)
			{
				size_t idx = str[i] - startValue_;
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
			TrieNode<nextcnt> * node = root_;
			for (size_t i = 0; i < str.length(); ++i)
			{
				size_t idx = str[i] - startValue_;
				if (node->nexts[idx] == nullptr)
					return 0;
				node = node->nexts[idx];
			}
			return node->path;
		}
	private:
		void add2Stack(TrieNode<nextcnt>**root, std::stack<TrieNode<nextcnt>**> &wait2Delete)
		{
			if (root == nullptr)
				return;
			wait2Delete.push(root);
			for (size_t i = 0; i < nextcnt; ++i)
				if ((*root)->nexts[i] != nullptr)
					add2Stack(&(*root)->nexts[i], wait2Delete);
		}

		void clearInStack(std::stack<TrieNode<nextcnt>**> &wait2Delete)
		{
			while (!wait2Delete.empty()) //ȫ�������
			{
				TrieNode<nextcnt>** tmp = wait2Delete.top();
				wait2Delete.pop();
				delete[](*tmp)->nexts;
				(*tmp)->nexts = nullptr;
				delete *tmp;
				*tmp = nullptr;
			}
		}

		/// <summary>
		/// dfs����ڴ�
		/// </summary>
		void clearRoot(TrieNode<nextcnt> ** root)
		{
			if ((*root) == nullptr)
				return;
			for (size_t i = 0; i < nextcnt; ++i)
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
		TrieNode<nextcnt>* root_;
		char startValue_;
	};

}

#endif // !TRIETREE_H
