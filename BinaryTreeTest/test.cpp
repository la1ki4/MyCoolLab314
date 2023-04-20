#include "pch.h"
#include <gtest/gtest.h>
#include "../MyCoolLab0/binaryTreeReal.hpp"

TEST(Tree, Search) {
	//Arrange
	BinaryTree<int> someTree;
	someTree.insert(7);

	//Act
	bool test = someTree.search(5);

	//Assert
	ASSERT_FALSE(test);
}

TEST(Tree, Insert)
{
	//Arrange
	BinaryTree<int> someTree;
	
	//Act
	someTree.insert(5);
	bool test = someTree.search(5);

	//Assert
	ASSERT_TRUE(test);
}

TEST(Tree, Remove)
{
	//Arrange
	BinaryTree<int> someTree;
	someTree.insert(5);

	//Act
	someTree.remove(5);
	bool test = someTree.search(5);

	//Assert
	ASSERT_FALSE(test);
}

TEST(Tree, SimmetricBypass)
{
	//Arrange
	const size_t size = 10;
	BinaryTree<int> someTree;
	for (size_t i = 0; i < size; i++)
	{
		someTree.insert(i);
	}

	//Act
	someTree.simmetricBypass();

	//Assert (empty for this test)
}

TEST(Tree, DirectBypass)
{
	//Arrange
	const size_t size = 10;
	BinaryTree<int> someTree;
	for (size_t i = 0; i < size; i++)
	{
		someTree.insert(i);
	}

	//Act
	someTree.directBypass();

	//Assert (empty for this test)
}

TEST(Tree, ReverseBypass)
{
	//Arrange
	const size_t size = 10;
	BinaryTree<int> someTree;
	for (size_t i = 0; i < size; i++)
	{
		someTree.insert(i);
	}

	//Act
	someTree.reverseBypass();

	//Assert (empty for this test)
}