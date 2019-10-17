#ifndef DATE_H
#define DATE_H

class Date {
public:
  Date() {}
  void set(const int m=0, const int d=0,const int y=0);
  const void print();
  inline const int get_month();
  inline const int get_day();
  inline const int get_year();
private:
  int month, day, year;
};

#endif

