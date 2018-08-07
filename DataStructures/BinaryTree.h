#ifndef BINARYTREE_H_
#define BINARYTREE_H_
#include <memory>
#include <string>
#include <iostream>
#include <stack>
#include <queue>
#include <algorithm>
using std::string;
using std::shared_ptr;
using std::endl;
using std::cout;
#define USE_INT

namespace yxp_utility
{

#pragma region shared_ptrģ��汾
	template<class T>
	struct BinaryTreeNode
	{
		typedef shared_ptr<BinaryTreeNode<T>> pBTN;
		T elem;
		pBTN left;
		pBTN right;

		BinaryTreeNode(const T&elem, const pBTN& left, const pBTN& right) :
			elem(elem), left(left), right(right)
		{
		}

		BinaryTreeNode(const T&elem) :
			elem(elem), left(nullptr), right(nullptr)
		{
		}

	};
#pragma endregion


#pragma region shared_ptr int�汾
	struct iBinaryTreeNode
	{
		typedef shared_ptr<iBinaryTreeNode> pBTN;
		int elem;
		pBTN left;
		pBTN right;

		iBinaryTreeNode(const int elem, const pBTN& left, const pBTN& right) :
			elem(elem), left(left), right(right)
		{
		}

		iBinaryTreeNode(const int elem) :
			elem(elem), left(nullptr), right(nullptr)
		{
		}
	};
#pragma endregion


#pragma region ��ָͨ��ģ��汾
#ifdef USE_TEMP
	template<class T>
	struct TreeNode *
	{
		T val;
		TreeNode *<T>* left;
		TreeNode *<T>* right;

		TreeNode *(const T&val, const TreeNode *<T>* left, const TreeNode *<T>* right) :
			val(val), left(left), right(right)
		{
		}

		TreeNode *(const T&val) :
			val(val), left(nullptr), right(nullptr)
		{
		}
	};

	template<class T<
		void DestoyTree(TreeNode *<T> *head)
	{
		if (head == nullptr)
			return;
		TreeNode *<T> *left = head->left;
		TreeNode *<T> *right = head->right;

		delete head;
		head = nullptr;
		DestoyTree(left);
		DestoyTree(right);
	}
#endif
#pragma endregion


#pragma region ��ָͨ��int�汾
#ifdef USE_INT

	struct TreeNode
	{
		int val;
		TreeNode*left;
		TreeNode*right;
		TreeNode(int val) :val(val), left(nullptr), right(nullptr) {}
	};

	void DestoyTree(TreeNode *head)
	{
		if (head == nullptr)
			return;
		TreeNode *left = head->left;
		TreeNode *right = head->right;

		delete head;
		head = nullptr;
		DestoyTree(left);
		DestoyTree(right);
	}

	//����˳�������
	TreeNode *GetExampleTree1()
	{
		TreeNode* head = new TreeNode(1);
		head->left = new TreeNode(2);
		head->right = new TreeNode(3);
		head->left->left = new TreeNode(4);
		head->left->right = new TreeNode(5);
		head->right->left = new TreeNode(6);
		head->right->right = new TreeNode(7);
		head->left->left->left = new TreeNode(8);
		head->left->left->right = new TreeNode(9);
		return head;
	}

	//����˳�������
	TreeNode *GetExampleTree2()
	{
		TreeNode* head = new TreeNode(4);
		head->left = new TreeNode(2);
		head->right = new TreeNode(6);
		head->left->left = new TreeNode(1);
		head->left->right = new TreeNode(3);
		head->right->left = new TreeNode(5);
		head->right->right = new TreeNode(7);
		return head;
	}


	std::vector<int> levelOrderTraversal(TreeNode *root)
	{
		if (root == nullptr)
			return{};
		std::vector<int> res;
		std::queue<TreeNode *> queue;
		queue.push(root);
		while (!queue.empty())
		{
			TreeNode * cur = queue.front();
			res.push_back(cur->val);
			queue.pop();
			if (cur->left != nullptr)
				queue.push(cur->left);
			if (cur->right != nullptr)
				queue.push(cur->right);
		}
		return res;
	}

		
	/// <summary>
	/// �ǵݹ�����������������vector��
	/// </summary>
	std::vector<int> preOrderTraversal(TreeNode *root)
	{
		if (root == nullptr)
			return{};
		std::stack<TreeNode*> stack;
		std::vector<int> res;
		stack.push(root);
		while (!stack.empty())
		{
			TreeNode* cur = stack.top();
			res.push_back(cur->val);
			stack.pop();
			if (cur->right != nullptr)
				stack.push(cur->right);
			if (cur->left != nullptr)
				stack.push(cur->left);
		}
		return res;
	}

	/// <summary>
	/// �ǵݹ�������
	/// </summary>
	std::vector<int> posOrderTraversal(TreeNode *root)
	{
		if (root == nullptr)
			return{};
		std::stack<TreeNode*> stack;
		std::stack<TreeNode*> stackReverse;
		stack.push(root);
		while (!stack.empty())
		{
			stackReverse.push(stack.top());
			stack.pop();
			if (stackReverse.top()->left != nullptr)
				stack.push(stackReverse.top()->left);
			if (stackReverse.top()->right != nullptr)
				stack.push(stackReverse.top()->right);
		}
		std::vector<int> res;
		res.reserve(stackReverse.size());
		while (!stackReverse.empty())
		{
			res.push_back(stackReverse.top()->val);
			stackReverse.pop();
		}
		return res;
	}

	//������߽�
	void PushLeftBorder(std::stack<TreeNode*>& s, TreeNode * node)
	{
		while (node != nullptr)
		{
			s.push(node);
			node = node->left; //ÿ��ֻѹ���ӽ�ȥ
		}
	}

	//�������
	std::vector<int> inOrderTraversal(TreeNode * head)
	{
		if (head == nullptr)
			return{};
		std::vector<int> res;
		std::stack<TreeNode *> stack;
		PushLeftBorder(stack, head); //��ѹ��߽�
		while (!stack.empty())
		{
			TreeNode * cur = stack.top(); //������������ʱ���Ƿ����Һ���
			stack.pop();
			res.push_back(cur->val);
			if (cur->right != nullptr)
				PushLeftBorder(stack, cur->right);
		}
		return res;
	}

	//��߶�
	int getHeight(TreeNode * head)
	{
		if (head == nullptr)
			return 0;
		return std::max(getHeight(head->left), getHeight(head->right)) + 1;
	}


#pragma region ���л��������л�
	std::string serialByPre(TreeNode *head)
	{
		if (head == nullptr)
			return "#!";
		std::string res = std::to_string(head->val) + "!";
		res += serialByPre(head->left);
		res += serialByPre(head->right);
		return res;
	}

	std::string serialByIn(TreeNode *head)
	{
		if (head == nullptr)
			return "#!";
		std::string res;
		res += serialByIn(head->left);
		res += std::to_string(head->val) + "!";
		res += serialByIn(head->right);
		return res;
	}

	std::string serialByPos(TreeNode *head)
	{
		if (head == nullptr)
			return "#!";
		std::string res;
		res += serialByPos(head->left);
		res += serialByPos(head->right);
		res += std::to_string(head->val) + "!";
		return res;
	}

	TreeNode * reconByPreSerialProcess(std::queue<std::string> &queue)
	{
		std::string val = queue.front();
		queue.pop();
		if (val == "#")
			return nullptr;
		TreeNode * root = new TreeNode(stoi(val));
		root->left = reconByPreSerialProcess(queue);
		root->right = reconByPreSerialProcess(queue);
		return root;
	}

	TreeNode * reconByPreSerial(const std::string& preSerial)
	{
		std::queue<std::string> queue;
		size_t pre = 0;
		for (size_t i = 0; i < preSerial.length(); ++i)
		{
			if (preSerial[i] == '!') //����!����һ��
			{
				queue.push(preSerial.substr(pre, i - pre));
				pre = i + 1;
			}
		}
		return reconByPreSerialProcess(queue);
	}

	TreeNode * reconByPosSerialProcess(std::stack<std::string> &stack)
	{
		std::string val = stack.top();
		stack.pop();
		if (val == "#")
			return nullptr;
		TreeNode * root = new TreeNode(stoi(val));
		root->right = reconByPosSerialProcess(stack); //ע�⣬������������������!!!
		root->left = reconByPosSerialProcess(stack);

		return root;
	}

	TreeNode * reconByPosSerial(const std::string& preSerial)
	{
		std::stack<std::string> stack;
		size_t pre = 0;
		for (size_t i = 0; i < preSerial.length(); ++i)
		{
			if (preSerial[i] == '!') //����!����һ��
			{
				stack.push(preSerial.substr(pre, i - pre));
				pre = i + 1;
			}
		}
		return reconByPosSerialProcess(stack);
	}

#pragma endregion


#endif
#pragma endregion


#pragma region ��ӡһ�����İ汾�������滻�������typedef�Ϳ�����Բ�ͬ�İ汾��
#ifdef USE_INT
	typedef TreeNode* ipBTN;
#else
	typedef shared_ptr<BinaryTreeNode<int>> ipBTN;
#endif
	void PrintTree(ipBTN head);
	void PrintInOrder(ipBTN head, int height, std::string to, int len);
	std::string GetSpace(int num);

	void PrintTree(ipBTN head)
	{
		//System.out.println("Binary Tree:");
		PrintInOrder(head, 0, "H", 17);
	}

	void PrintInOrder(ipBTN head, int height, std::string to, int len)
	{
		if (head == nullptr)
		{
			return;
		}
		PrintInOrder(head->right, height + 1, "v", len);
		string val = to + std::to_string(head->val) + to;
		int lenM = val.length();
		int lenL = (len - lenM) / 2;
		int lenR = len - lenM - lenL;
		val = GetSpace(lenL) + val + GetSpace(lenR);
		cout << (GetSpace(height * len) + val) << endl;
		PrintInOrder(head->left, height + 1, "^", len);
	}

	std::string GetSpace(int num)
	{
		string space = " ";
		string buf;
		for (int i = 0; i < num; i++)
			buf += space;
		return buf;
	}
#endif
}

