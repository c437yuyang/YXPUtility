#ifndef TRIETREE_H
#define TRIETREE_H
#include <stack>
namespace yxp_utility
{

	struct TrieNode
	{
	public:
		int path; //��������ڵ��·����Ŀ
		int end; //����ڵ��β��·����Ŀ
		TrieNode **nexts;

		TrieNode() :path(0), end(0), nexts(new TrieNode*[26])
		{
			for (size_t i = 0; i < 26; ++i)
				nexts[i] = nullptr;//ÿ���ڵ㣬�������п��ܵ�26��·��
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
			std::stack<TrieNode**> wait2Delete; //��Ϊָ���ǿ����ģ�����Ҫ������ָ��
			TrieNode * node = root_; //������һ���ҵõ���
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
			while (!wait2Delete.empty()) //ȫ�������
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
		/// dfs����ڴ�
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
