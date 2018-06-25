#include <gtest/gtest.h>
#include <DataStructures/TrieTree.h>
using namespace yxp_utility;


TEST(TrieTreeTest, demo1)
{
	TrieTree trie;
	EXPECT_EQ(trie.count("zuo"), 0);
	trie.insert("zuo");
	EXPECT_EQ(trie.count("zuo"), 1);

	trie.remove("zuo");
	EXPECT_EQ(trie.count("zuo"), 0);
	trie.insert("zuo");
	trie.insert("zuo");
	trie.remove("zuo");
	EXPECT_EQ(trie.count("zuo"), 1);
	trie.remove("zuo");
	EXPECT_EQ(trie.count("zuo"), 0);

	trie.insert("zuoa");
	trie.insert("zuoac");
	trie.insert("zuoab");
	trie.insert("zuoad");
	trie.remove("zuoa");
	EXPECT_EQ(trie.count("zuo"), 0);
	EXPECT_EQ(trie.prefixCount("zuo"), 3);

	trie.clear();
	EXPECT_EQ(trie.count("zuo"), 0);
	EXPECT_EQ(trie.prefixCount("zuo"), 0);

	trie.insert("zuoa");
	trie.insert("zuoac");
	trie.insert("zuoab");
	trie.insert("zuoad");
	trie.remove("zuoa");
	EXPECT_EQ(trie.count("zuo"), 0);
	EXPECT_EQ(trie.prefixCount("zuo"), 3);
}