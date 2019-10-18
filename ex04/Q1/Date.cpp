#include <iostream>
#include "Date.h"

// month, date, year
void Date::set(const int m, const int d, const int y)
{
  month = m;
  day = d;
  year = y;
}

// date stored in the object
void Date::print()
{
  std::cout << "MONTH : " << month
            << ", DAY : " << day
            << ", YEAR : " << year << std::endl;
}

// return respectively the month, the day and the year stored in a Date object
/*
int Date::get_month() const{}
int Date::get_day() const{}
int Date::get_year() const{}
*/
