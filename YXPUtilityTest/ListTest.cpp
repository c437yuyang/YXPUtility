
#include <gtest/gtest.h>
#include "DataStructures/List.h"
using namespace yxp_utility;


TEST(ListTest, IsPalindrometest1)
{
	ListNode * head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(2);
	head->next->next->next = new ListNode(1);

	EXPECT_EQ(isPalindrome(head), true);

}

TEST(ListTest, IsPalindrometest2)
{
	ListNode * head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(2);
	head->next->next->next->next = new ListNode(1);

	EXPECT_EQ(isPalindrome(head), true);

}

TEST(ListTest, IsPalindrometest3)
{
	ListNode * head = new ListNode(1);
	head->next = new ListNode(3);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(2);
	head->next->next->next->next = new ListNode(1);

	EXPECT_EQ(isPalindrome(head), false);
}