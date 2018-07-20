#include <gtest/gtest.h>
#include "DataStructures/BinaryTree.h"
using namespace yxp_utility;

TEST(BinaryTreeTest, TraversalTest)
{
	TreeNode* node = GetExampleTree1();
	std::vector<int> res{ 1,2,4,8,9,5,3,6,7 };
	EXPECT_EQ(preOrderTraversal(node), res);
	res = {8,4,9,2,5,1,6,3,7 };
	EXPECT_EQ(inOrderTraversal(node), res);
	res = { 8,9,4,5,2,6,7,3,1};
	EXPECT_EQ(posOrderTraversal(node), res);

	res = { 1,2,3,4,5,6,7,8,9};
	EXPECT_EQ(levelOrderTraversal(node), res);
}


TEST(BinaryTreeTest, GetiHeightTest)
{
	TreeNode* node = GetExampleTree1();
	EXPECT_EQ(getHeight(node), 4);
}


TEST(BinaryTreeTest, SerialTest)
{
	TreeNode* node = GetExampleTree1();
	std::string res = "1!2!4!8!#!#!9!#!#!5!#!#!3!6!#!#!7!#!#!";
	EXPECT_EQ(serialByPre(node), res);

	res = "#!#!8!#!#!9!4!#!#!5!2!#!#!6!#!#!7!3!1!";
	EXPECT_EQ(serialByPos(node), res);

}


TEST(BinaryTreeTest, reconPreSerialTest)
{
	TreeNode* node = GetExampleTree1();
	std::string res = "1!2!4!8!#!#!9!#!#!5!#!#!3!6!#!#!7!#!#!";
	EXPECT_EQ(serialByPre(node), res);
	TreeNode * reconHead = reconByPreSerial(res);
	EXPECT_EQ(serialByPre(reconHead),res);
}

TEST(BinaryTreeTest, reconPosSerialTest)
{
	TreeNode* node = GetExampleTree1();
	std::string res = "#!#!8!#!#!9!4!#!#!5!2!#!#!6!#!#!7!3!1!";
	EXPECT_EQ(serialByPos(node), res);
	TreeNode * reconHead = reconByPosSerial(res);
	EXPECT_EQ(serialByPos(reconHead), res);
}