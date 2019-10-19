#ifndef DATE_H
#define DATE_H

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


class Date2 {
public:
  Date2() {}
  void set(const int m=0, const int d=0, const int y=0);
  const void print();
  inline int get_month() const{return month;}
  inline int get_day() const{return day;}
  inline int get_year() const{return year;}
private:
  int month, day, year;
};

#endif

