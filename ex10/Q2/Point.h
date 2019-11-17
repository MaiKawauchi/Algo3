#ifndef _POINT_H_
#define _POINT_H_

#include <iostream>
#include <iterator>
#include <cstdlib>

using namespace std;

struct Point {
  int x, y;
};

struct Point_hash{
  size_t operator()(const Point& p) const {
    size_t P = 0;
    hash<int> Ps;
    hash<int> Pi;
    P = Ps(p.x) ^ Pi(p.y);
    return P;
  }
};

struct Point_equal{
  bool operator() (const Point& p1, const Point& p2) const {
    return (p1.x==p2.x) && (p1.y == p2.y);
  }
};


#endif
