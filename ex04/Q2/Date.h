#ifndef DATE_H
#define DATE_H

class Date {
public:
  Date() {}
  void set(int m=0, int d=0, int y=0);
  void print();
  const int get_month();
  const int get_day();
  const int get_year();
private:
  int month, day, year;
};

#endif

