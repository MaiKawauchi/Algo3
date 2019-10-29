#include <iostream>
#include "Circle.h"
#include "test_Shape2D.cpp"

using namespace std;

Circle::Circle(Point2D c, float r)
  : center(c)
  , radius(r){
}

string Circle::get_name()const{
  return "Circle";
}
float Circle::compute_area()const{
  return radius * radius * PI;
}
void Circle::translate(float tx, float ty){
}
