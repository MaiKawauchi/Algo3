#ifndef DATE_H
#define DATE_H

class Date {
public:
  Date() {}
  void set(const int m=0, const int d=0, const int y=0);
  void print();
  int get_month() const{ return month; }
  int get_day() const { return day; }
  int get_year() const { return year; }
private:
  int month, day, year;
};

#endif

