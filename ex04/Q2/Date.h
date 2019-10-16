#ifndef DATE_H
#define DATE_H

class Date {
public:
  Date() {}
  void set(int m=0, int d=0, int y=0);
  void print();
  inline const int get_month();
  inline const int get_day();
  inline const int get_year();
private:
  int month, day, year;
};

#endif

