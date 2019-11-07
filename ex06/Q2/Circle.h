#ifndef Circle_h
#define Circle_h

#include <iostream>
#include "Shape2D.h"

using namespace std;

class Circle : public Shape2D{
public:
  //constructor
  Circle();
  Circle(Point2D center, float radius);

  string get_name()const override;
  float compute_area()const override;
  void translate(float tx, float ty) override;

  ~Circle();

private:
  Point2D center;
  float radius;
};

#endif // Circle_h
