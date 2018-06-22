#include <iostream>
struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};

void DestroyList(ListNode* head)
{
	while (head != nullptr)
	{
		ListNode*next = head->next;
		delete head;
		head = next;
	}
}

void PrintList(ListNode *head)
{
	while (head != nullptr)
	{
		std::cout << head->val << " ";
		head = head->next;;
	}
	std::cout << endl;
}