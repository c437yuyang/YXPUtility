#ifndef BINARYTREE_H_
#define BINARYTREE_H_
#include <memory>
#include <string>
#include <iostream>
using std::string;
using std::shared_ptr;
using std::endl;
using std::cout;
#define USE_INT


#pragma region shared_ptr模板版本
template<class T>
struct BinaryTreeNode
{
	typedef shared_ptr<BinaryTreeNode<T>> pBTN;
	T elem;
	pBTN left;
	pBTN right;

	BinaryTreeNode(const T&elem, const pBTN& left, const pBTN& right) :
		elem(elem), left(left), right(right) {}

	BinaryTreeNode(const T&elem) :
		elem(elem), left(nullptr), right(nullptr) {}

};
#pragma endregion


#pragma region shared_ptr int版本
struct iBinaryTreeNode
{
	typedef shared_ptr<iBinaryTreeNode> pBTN;
	int elem;
	pBTN left;
	pBTN right;

	iBinaryTreeNode(const int elem, const pBTN& left, const pBTN& right) :
		elem(elem), left(left), right(right) {}

	iBinaryTreeNode(const int elem) :
		elem(elem), left(nullptr), right(nullptr) {}
};
#pragma endregion


#pragma region 普通指针模板版本
#ifdef USE_TEMP
template<class T>
struct Node
{
	T val;
	Node<T>* left;
	Node<T>* right;

	Node(const T&val, const Node<T>* left, const Node<T>* right) :
		val(val), left(left), right(right) {}

	Node(const T&val) :
		val(val), left(nullptr), right(nullptr) {}
};

template<class T<
void DestoyTree(Node<T> *head)
{
	if (head == nullptr)
		return;
	Node<T> *left = head->left;
	Node<T> *right = head->right;

	delete head;
	head = nullptr;
	DestoyTree(left);
	DestoyTree(right);
}
#endif
#pragma endregion


#pragma region 普通指针int版本
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

//常用的例子二叉树
TreeNode *GetExampleTree()
{
	TreeNode* head = new TreeNode(1);
	head->left = new TreeNode(2);
	head->right = new TreeNode(3);
	head->left->left = new TreeNode(4);
	head->left->right = new TreeNode(5);
	head->right->left = new TreeNode(6);
	head->right->right = new TreeNode(7);
	head->left->left->left = new TreeNode(8);
	head->right->left->right = new TreeNode(9);
	return head;
}

#endif
#pragma endregion


#pragma region 打印一棵树的版本，自行替换下面这个typedef就可以针对不同的版本了
#ifdef USE_INT
typedef TreeNode* ipBTN;
#else
typedef shared_ptr<BinaryTreeNode<int>> ipBTN;
#endif


void printTree(ipBTN head);
void printInOrder(ipBTN head, int height, string to, int len);
string getSpace(int num);


void printTree(ipBTN head) {
	//System.out.println("Binary Tree:");
	printInOrder(head, 0, "H", 17);
}

void printInOrder(ipBTN head, int height, string to, int len) {
	if (head == nullptr) {
		return;
	}
	printInOrder(head->right, height + 1, "v", len);
	char buf[10];
	_itoa_s(head->val, buf, 10);
	string val = to + buf + to;
	int lenM = val.length();
	int lenL = (len - lenM) / 2;
	int lenR = len - lenM - lenL;
	val = getSpace(lenL) + val + getSpace(lenR);
	cout << (getSpace(height * len) + val) << endl;
	printInOrder(head->left, height + 1, "^", len);
}

string getSpace(int num) {
	string space = " ";
	string buf;
	for (int i = 0; i < num; i++) {
		buf += space;
	}
	return buf;
}
#endif

