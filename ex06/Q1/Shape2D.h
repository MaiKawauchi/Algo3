#ifndef SHAPE2D_H
#define SHAPE2D_H

#include <cmath>
#include <cassert>
#include <iostream>
#include <cstring>

using namespace std;

inline void assertFloat(float x, float y, float eps=1e-5) {
  assert(std::fabs(x-y) < eps);
}



class Point2D{
public:
  Point2D(float x, float y)
    : x(x)
    , y(y){
  }
  float x;
  float y;
};


class Shape2D{
public:
  /* プリミティブの名前に対応する文字列を返す */
  virtual string get_name() const = 0;
  /* 形状の面積を返す */
  virtual float compute_area() const = 0;
  /* 形状をx方向にtx、y方向にtyだけ変換 */
  virtual void translate(float tx, float ty) = 0;

  virtual ~Shape2D();
};


#endif // SHAPE2D_H
