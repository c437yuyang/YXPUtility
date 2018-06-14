#ifndef _BINARYTREENODE_H_
#define _BINARYTREENODE_H_
#include <memory>
#include <string>
#include <iostream>
using std::string;
using std::shared_ptr;
using std::endl;
using std::cout;


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
		elem(elem), left(NULL), right(NULL) {}

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
		elem(elem), left(NULL), right(NULL) {}
};
#pragma endregion



#pragma region 普通指针模板版本
template<class T>
struct Node
{
	T elem;
	Node<T>* left;
	Node<T>* right;

	Node(const T&elem, const Node<T>* left, const Node<T>* right) :
		elem(elem), left(left), right(right) {}

	Node(const T&elem) :
		elem(elem), left(NULL), right(NULL) {}

};
#pragma endregion


#pragma region 普通指针int版本
struct iNode
{
	int elem;
	iNode* left;
	iNode* right;

	iNode(int elem, iNode* left, iNode* right) :
		elem(elem), left(left), right(right) {}

	iNode(int elem) :
		elem(elem), left(NULL), right(NULL) {}
};
#pragma endregion


#pragma region 打印一棵树的版本，自行替换下面这个typedef就可以针对不同的版本了
typedef shared_ptr<BinaryTreeNode<int>> ipBTN;
void printTree(ipBTN head);
void printInOrder(ipBTN head, int height, string to, int len);
string getSpace(int num);


void printTree(ipBTN head) {
	//System.out.println("Binary Tree:");
	printInOrder(head, 0, "H", 17);
}

void printInOrder(ipBTN head, int height, string to, int len) {
	if (head == NULL) {
		return;
	}
	printInOrder(head->right, height + 1, "v", len);
	char buf[10];
	_itoa_s(head->elem, buf, 10);
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