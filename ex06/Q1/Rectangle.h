#ifndef Rectangle_h
#define Rectangle_h

#include <iostream>
#include "Shape2D.h"

using namespace std;

class Rectangle : public Shape2D{
public:
  Rectangle();
  Rectangle(Point2D left_corner, const float width, const float height);
  string get_name()const override;
  float compute_area()const override;
  void translate(float tx, float ty) override;

  ~Rectangle();
private:
  Point2D left_corner;
  float width;
  float height;
};

#endif // Rectangle_h
