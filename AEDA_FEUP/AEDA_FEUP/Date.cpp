#include "Date.h"

Date::Date()
{
	day = 0;
	month = 0;
	year = 0;
}

Date::Date(int day, int month, int year)
{
	this->day = day;
	this->month = month;
	this->year = year;
}

void Date::setDay(int day)
{
	this->day = day;
}

int Date::getDay()
{
	return day;
}

void Date::setMonth(int month)
{
	this->month = month;
}

int Date::getMonth()
{
	return month;
}

void Date::setYear(int year)
{
	this->year = year;
}

int Date::getYear()
{
	return year;
}

bool Date::isValid()
{

	if (this->getMonth() < 1 || this->getMonth() > 12)
	{
		return false;
	}
	if (this->getYear() < 1969 || this->getYear() > 2016)
	{
		return false;
	}
	if (this->getMonth() == 1 || this->getMonth() == 5 || this->getMonth() == 7 || this->getMonth() == 10 || this->getMonth() == 3 || this->getMonth() == 12 || this->getMonth() == 8)
	{
		if (this->getDay() < 1 || this->getDay() > 31)
		{
			return false;
		}
	}
	if (this->getMonth() == 4 || this->getMonth() == 6 || this->getMonth() == 9 || this->getMonth() == 11)
	{
		if (this->getDay() < 1 || this->getDay() > 30)
		{
			return false;
		}
	}
	if (this->getMonth() == 2 && (this->getDay() < 1 || this->getDay() > 28))
		return false;
	return true;
}

bool Date::operator<(Date x)
{
	if (this->getYear() < x.getYear())
		return true;
	if (this->getYear() > x.getYear())
		return false;
	if (this->getMonth() < x.getMonth())
		return true;
	if (this->getMonth() > x.getMonth())
		return false;
	if (this->getDay() < x.getDay())
		return true;
	if (this->getDay() > x.getDay())
		return false;
	else
		return true;
}

bool Date::operator>(Date x)
{
	if (this->getYear() > x.getYear())
		return true;
	if (this->getYear() < x.getYear())
		return false;
	if (this->getMonth() > x.getMonth())
		return true;
	if (this->getMonth() < x.getMonth())
		return false;
	if (this->getDay() > x.getDay())
		return true;
	if (this->getDay() < x.getDay())
		return false;
	else
		return true;
}