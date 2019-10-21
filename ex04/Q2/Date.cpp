#include <iostream>
#include "Date.h"

/*--------------------------------Way1--------------------------------------
// month, date, year
void Date::set(const int m, const int d, const int y)
{
    month = m;
    day = d;
    year = y;
}

// date stored in the object
const void Date::print()
{
  std::cout << "MONTH: " << month
            << ", DAY: " << day
            << ", YEAR: " << year << std::endl;
}
--------------------------------------------------------------------------*/


/*---------------------------------Way2-------------------------------------
void Date2::set(const int m, const int d, const int y)
{
  month = m;
  day = d;
  year = y;
}

const void Date2::print()
{
  std::cout << "MONTH: " << month
            << ", DAY: " << day
            << ", YEAR: " << year << std::endl;
}
-------------------------------------------------------------------------- */
