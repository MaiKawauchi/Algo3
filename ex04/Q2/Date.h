#ifndef DATE_H
#define DATE_H

#include <iostream>

class Date {
public:
  Date() {}
  void set(const int m=0, const int d=0,const int y=0);
  const void print();
  int get_month() const;
  int get_day() const;
  int get_year() const;
private:
  int month, day, year;
};

inline void Date::set(const int m, const int d, const int y)
{
  month = m;
  day = d;
  year = y;
}
inline const void Date::print()
{
  std::cout << "MONTH: " << month
            << ", DAY: " << day
            << ", YEAR: " << year << std::endl;
}
inline int Date::get_month() const{return month;}
inline int Date::get_day() const{return day;}
inline int Date::get_year() const{return year;}

/*-------------------------------------------------------------------------- */

class Date2 {
public:
  Date2() {}

  void set(const int m=0, const int d=0, const int y=0)
  {
    month = m;
    day = d;
    year = y;
  }

  const void print()
  {
    std::cout << "MONTH: " << month
              << ", DAY: " << day
              << ", YEAR: " << year << std::endl;
  }

  int get_month() const{return month;}
  int get_day() const{return day;}
  int get_year() const{return year;}

private:
  int month, day, year;
};

#endif

