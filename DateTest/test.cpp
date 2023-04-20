#include "pch.h"
#include "../MyCoolLab0/DateReal.hpp"

TEST(date, CopyOperator) {

	//Arrange
	Date obj1(12, 2, 2003);
	
	//Act
	Date obj2 = obj1;

	//Assert
	ASSERT_EQ(obj1, obj2);
}

TEST(date, ComparationOperator)
{
	//Arrange
	Date obj1(12, 2, 2003);
	Date obj2 = obj1;

	//Act (empty for this test)

	//Assert
	ASSERT_EQ(obj1, obj2);
}

TEST(date, GetDay)
{
	//Arrange
	Date obj1(12, 2, 2003);

	//Act
	unsigned short day = obj1.Day();

	//Assert
	ASSERT_EQ(12, day);
}

TEST(date, GetMonth)
{
	//Arrange
	Date obj1(12, 2, 2003);

	//Act
	unsigned short month = obj1.Month();

	//Assert
	ASSERT_EQ(2, month);
}

TEST(date, GetYear)
{
	//Arrange
	Date obj1(12, 2, 2003);

	//Act
	unsigned short year = obj1.Year();

	//Assert
	ASSERT_EQ(2003, year);
}

