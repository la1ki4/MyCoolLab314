#include "pch.h"
#include <gtest/gtest.h>
#include "../MyCoolLab0/singlyLinkedListReal.hpp"

TEST(List, Size)
{
	//Arrange
	singlyLinkedList<int> someList;

	//Act
	someList.push_back(2);

	//Assert
	ASSERT_EQ(someList.getSize(), 1);
}

TEST(List, Empty) {

	//Arrange
	singlyLinkedList<int> someList;

	//Act (empty for this test)

	//Assert
	ASSERT_EQ(someList.getSize(), 0);
	ASSERT_TRUE(someList.isEmpty());
}

TEST(List, PushBack)
{
	//Arrange
	const size_t count = 10;
	singlyLinkedList<int> someList;

	//Act
	for (size_t i = 0; i < count; i++)
	{
		someList.push_back(i);
	}

	//Assert
	ASSERT_EQ(count, someList.getSize());
	ASSERT_EQ(someList[0] + 9, someList[9]);
	ASSERT_FALSE(someList.isEmpty());
}

TEST(List, PushFront)
{
	//Arrange
	const size_t count = 10;
	singlyLinkedList<int> someList;

	//Act
	for (size_t i = 0; i < count; i++)
	{
		someList.push_front(i);
	}

	//Assert
	ASSERT_EQ(count, someList.getSize());
	ASSERT_EQ(someList[0] - 9, someList[9]);
	ASSERT_FALSE(someList.isEmpty());
}

TEST(List, PopBack)
{
	//Arrange
	const size_t count = 10;
	singlyLinkedList<int> someList;

	//Act
	for (size_t i = 0; i < count; i++)
	{
		someList.push_back(i);
	}
	someList.pop_back();

	//Assert
	ASSERT_EQ(someList.getSize(), 9);
	ASSERT_FALSE(someList.isEmpty());
}

TEST(List, PopFront)
{
	//Arrange
	const size_t count = 10;
	singlyLinkedList<int> someList;

	//Act
	for (size_t i = 0; i < count; i++)
	{
		someList.push_front(i);
	}
	someList.pop_front();

	//Assert
	ASSERT_NE(count, someList.getSize());
	ASSERT_FALSE(someList.isEmpty());
}

TEST(List, Search)
{
	//Arrange
	const size_t count = 10;
	singlyLinkedList<int> someList;

	//Act
	for (size_t i = 0; i < count; i++)
	{
		someList.push_back(i);
	}
	int index = someList.search(5);

	//Assert
	ASSERT_EQ(someList[index], 5);
}
TEST(List, Insert)
{
	//Arrange
	const size_t count = 10;
	singlyLinkedList<int> someList;
	
	//Act
	for (size_t i = 0; i < count; i++)
	{
		someList.push_back(i);
	}
	someList.insert(8, 5);
	
	//Assert
	ASSERT_EQ(someList[5], 8);
}

TEST(List, RemoveElement)
{
	//Arrange
	const size_t count = 10;
	singlyLinkedList<int> someList;
	for (size_t i = 0; i < count; i++)
	{
		someList.push_back(i);
	}

	//Act
	someList.removeAt(4);

	//Assert
	ASSERT_NE(someList[4], 4);
}

TEST(List, Print)
{
	//Arrange
	const size_t count = 10;
	singlyLinkedList<int> someList;
	for (size_t i = 0; i < count; i++)
	{
		someList.push_back(i);
	}

	//Act (empty for this test)

	//Assert
	someList.printList();
	
}

