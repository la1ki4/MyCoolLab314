#include "DateInit.hpp"

Date::Date()
    : day(0), month(0), year(0)
{
}

Date::Date(const unsigned short& _day, const unsigned short& _month, const unsigned short& _year)
    :day(_day), month(_month), year(_year)
{
}

Date::Date(const Date& birthYear) : day(birthYear.day), month(birthYear.month), year(birthYear.year)
{
}

bool Date::operator==(const Date& birthYear) const
{
    return day == birthYear.day && month == birthYear.month && year == birthYear.year;
}

const Date& Date::operator=(const Date& birthYear)
{
    day = birthYear.day;
    month = birthYear.month;
    year = birthYear.year;

    return *this;
}

unsigned short Date::Day() const
{
    return day;
}

unsigned short Date::Month() const
{
    return month;
}

unsigned short Date::Year() const
{
    return year;
}