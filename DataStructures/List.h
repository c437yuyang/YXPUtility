#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <vector>
namespace yxp_utility
{
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

	/// <summary>
	/// 快慢指针法找到中间节点
	/// </summary>
	ListNode *FindMid(ListNode *head)
	{
		if (head == nullptr || head->next == nullptr)
		{
			return head;
		}
		ListNode *fast = head;
		ListNode *slow = head;
		while (fast->next != nullptr && fast->next->next != nullptr)
		{
			slow = slow->next;
			fast = fast->next->next;
		}
		return slow; //最后slow停留的位置就是中间节点
	}

	/// <summary>
	/// 翻转链表
	/// </summary>
	ListNode* ReverseList(ListNode* pHead)
	{
		if (pHead == nullptr || pHead->next == nullptr)
			return pHead;
		ListNode *prev = nullptr;
		while (pHead != nullptr)
		{
			ListNode *nextSave = pHead->next;
			pHead->next = prev;
			prev = pHead;
			pHead = nextSave;
		}
		return prev;

	}

	/// <summary>
	/// 直接合并两个链表,head1优先
	/// </summary>
	/// <param name="head1"></param>
	/// <param name="head2"></param>
	/// <returns></returns>
	ListNode *MergeListNoOrder(ListNode *head1, ListNode*head2)
	{
		if (head1 == nullptr)
			return head2;
		if (head2 == nullptr)
			return head1;

		ListNode * newHead = head1;
		ListNode * newCur = newHead;
		head1 = head1->next;
		bool hea1First = false;
		while (head1 != nullptr && head2 != nullptr)
		{
			newCur->next = hea1First ? head1 : head2;
			if (hea1First)
				head1 = head1->next;
			else
				head2 = head2->next;
			newCur = newCur->next;
			hea1First = !hea1First;
		}
		while (head1 != nullptr)
		{
			newCur->next = head1;
			head1 = head1->next;
			newCur = newCur->next;
		}

		while (head2 != nullptr)
		{
			newCur->next = head2;
			head2 = head2->next;
			newCur = newCur->next;
		}
		return newHead;
	}

	/// <summary>
	/// 按照从大到小重新排序两个链表
	/// </summary>
	ListNode *MergeList(ListNode *head1, ListNode *head2)
	{
		if (head1 == nullptr)
			return head2;
		if (head2 == nullptr)
			return head1;
		ListNode *newHead = nullptr;
		if (head1->val < head2->val)
		{
			newHead = head1;
			head1 = head1->next;
		}
		else
		{
			newHead = head2;
			head2 = head2->next;
		}
		ListNode *newCur = newHead;
		while (head1 != nullptr && head2 != nullptr)
		{
			if (head1->val < head2->val)
			{
				newCur->next = head1;
				head1 = head1->next;
			}
			else
			{
				newCur->next = head2;
				head2 = head2->next;
			}
			newCur = newCur->next;
		}
		while (head1 != nullptr)
		{
			newCur->next = head1;
			head1 = head1->next;
			newCur = newCur->next;
		}
		while (head2 != nullptr)
		{
			newCur->next = head2;
			head2 = head2->next;
			newCur = newCur->next;
		}
		return newHead;
	}

	/// <summary>
	/// 根据数组创建list
	/// </summary>
	ListNode * CreateList(const std::vector<int> &v)
	{
		if (v.empty())
			return nullptr;
		ListNode * head = new ListNode(v[0]);
		ListNode *cur = head;
		for (size_t i = 1; i < v.size(); ++i)
		{
			cur->next = new ListNode(v[i]);
			cur = cur->next;
		}
		return head;
	}

	/// <summary>
	/// 返回第idx个节点
	/// </summary>
	ListNode * GetListNodeAt(ListNode *head, size_t idx)
	{
		while (idx-- && head != nullptr)
			head = head->next;
		if (head == nullptr)
			throw std::runtime_error("invalid index!!!");
		return head;
	}

	/// <summary>
	/// 判断是否有环
	/// </summary>
	bool HasCycle(ListNode *head)
	{
		if (head == nullptr || head->next == nullptr)
			return false;
		if (head->next == head) //一个节点单独考虑
			return true;
		if (head->next->next == head) //只有两个节点单独考虑
			return true;
		ListNode *fast = head;
		ListNode *slow = head;
		while (fast != nullptr && fast->next != nullptr)
		{
			fast = fast->next->next;
			slow = slow->next;
			if (fast == slow) //找到第一次相遇的点
				break;
		}

		if (fast == nullptr || fast->next == nullptr)
			return false;
		return true;
	}


	/// <summary>
	/// 找到入环点
	/// </summary>
	ListNode *FindIntoCycle(ListNode *head)
	{
		if (head == nullptr || head->next == nullptr)
			return nullptr;
		if (head->next == head) //一个节点单独考虑
			return head;
		if (head->next->next == head) //只有两个节点单独考虑 (其实都不用单独考虑)
			return head;
		ListNode *fast = head;
		ListNode *slow = head;
		while (fast != nullptr && fast->next != nullptr
			)
		{
			fast = fast->next->next;
			slow = slow->next;
			if (fast == slow) //找到第一次相遇的点
				break;
		}

		if (fast == nullptr || fast->next == nullptr)
			return nullptr;

		slow = head; //一个节点再回到head
		while (slow != fast) //再次相遇就是入环点
		{
			slow = slow->next;
			fast = fast->next;
		}
		return slow;
	}

}
#endif