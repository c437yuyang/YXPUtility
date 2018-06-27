#ifndef LIST_H
#define LIST_H
#include <stdexcept>
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

	void DestroyList(ListNode *head)
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
		std::cout << std::endl;
	}

	/// <summary>
	/// ����ָ�뷨�ҵ��м�ڵ�
	/// </summary>
	ListNode *FindMid(ListNode *head)
	{
		if (head == nullptr || head->next == nullptr)
		{
			return head;
		}
		ListNode *fast = head;
		ListNode *slow = head;


		while (fast->next != nullptr && fast->next->next != nullptr)//��������ʱż����ʱ���ҵ���������λ�� 1->2->3->4 slow������2
		//while (fast != nullptr && fast->next != nullptr)//����������ż����ʱ���ҵ���������λ�� 1->2->3->4 slow������3
		{
			slow = slow->next;
			fast = fast->next->next;
		}
		return slow; //���slowͣ����λ�þ����м�ڵ�
	}

	/// <summary>
	/// ��ת����
	/// </summary>
	ListNode *ReverseList(ListNode *pHead)
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
	/// ֱ�Ӻϲ���������,head1����
	/// </summary>
	/// <param name="head1"></param>
	/// <param name="head2"></param>
	/// <returns></returns>
	ListNode *MergeListNoOrder(ListNode *head1, ListNode *head2)
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
	/// ���մӴ�С����������������
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
	/// �������鴴��list
	/// </summary>
	ListNode *CreateList(const std::vector<int> &v)
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
	/// ���ص�idx���ڵ�
	/// </summary>
	ListNode *GetListNodeAt(ListNode *head, size_t idx)
	{
		while (idx-- && head != nullptr)
			head = head->next;
		if (head == nullptr)
			throw std::runtime_error("invalid index!!!");
		return head;
	}

	/// <summary>
	/// �ж��Ƿ��л�
	/// </summary>
	bool HasCycle(ListNode *head)
	{
		if (head == nullptr || head->next == nullptr)
			return false;
		if (head->next == head) //һ���ڵ㵥������
			return true;
		if (head->next->next == head) //ֻ�������ڵ㵥������
			return true;
		ListNode *fast = head;
		ListNode *slow = head;
		while (fast != nullptr && fast->next != nullptr)
		{
			fast = fast->next->next;
			slow = slow->next;
			if (fast == slow) //�ҵ���һ�������ĵ�
				break;
		}

		if (fast == nullptr || fast->next == nullptr)
			return false;
		return true;
	}


	/// <summary>
	/// �ҵ��뻷��
	/// </summary>
	ListNode *FindIntoCycle(ListNode *head)
	{
		if (head == nullptr || head->next == nullptr)
			return nullptr;
		if (head->next == head) //һ���ڵ㵥������
			return head;
		if (head->next->next == head) //ֻ�������ڵ㵥������ (��ʵ�����õ�������)
			return head;
		ListNode *fast = head;
		ListNode *slow = head;
		while (fast != nullptr && fast->next != nullptr
			)
		{
			fast = fast->next->next;
			slow = slow->next;
			if (fast == slow) //�ҵ���һ�������ĵ�
				break;
		}

		if (fast == nullptr || fast->next == nullptr)
			return nullptr;

		slow = head; //һ���ڵ��ٻص�head
		while (slow != fast) //�ٴ����������뻷��
		{
			slow = slow->next;
			fast = fast->next;
		}
		return slow;
	}

	bool isPalindrome(ListNode *head)
	{
		if (head == nullptr)
			return false;
		else if (head->next == nullptr)
			return true;
		else
		{
			//����ָ���ҳ��м�ڵ�  
			ListNode* fast = head;
			ListNode* slow = head;

			while (fast->next != nullptr && fast->next->next != nullptr)
			{
				slow = slow->next;
				fast = fast->next->next;
			}
			//�ҵ�������һ����slow,(����λ��)

			ListNode *prev = slow;
			ListNode *rightHead = slow->next;
			while (rightHead!=nullptr)
			{
				ListNode * rightHeadNextSave = rightHead->next;
				rightHead->next = prev;
				prev = rightHead;
				rightHead = rightHeadNextSave;
			}
			rightHead = prev; //��ת�˹����ҵ��ұߵĿ�ͷ

			//��ͷ��β���м��������Ƚϣ�һ����һ��Ԫ�ز�������  
			while (head != rightHead)
			{
				if (head->val != rightHead->val)
					return false;
				else
				{
					if (head->next == rightHead) //ż���������,��������һֱһ���ߵ��м�ڵ㣬Ȼ������return true�����з���
						return true;
					head = head->next;
					rightHead = rightHead->next;
				}
			}


			//����ٷ�תһ�������ָ�ԭ��������ʱ��д��
			//ListNode *prev = 

			return true;
		}
	}
}
#endif
