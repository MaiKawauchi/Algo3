#ifndef DATE_H
#define DATE_H

class Date {
public:
  Date() {}
  void set(const int m=0, const int d=0, const int y=0);
  void print();
  int get_month() const;
  int get_day() const;
  int get_year() const;
private:
  int month, day, year;
};

#endif
