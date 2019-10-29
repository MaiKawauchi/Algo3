#include <iostream>
#include "Circle.h"

using namespace std;
extern const float PI;

Circle::Circle(Point2D c, float r)
  : center(c)
  , radius(r){
}

string Circle::get_name()const{
  cout << "Circle" << endl;
  return "Circle";
}
float Circle::compute_area()const{
  return radius * radius * PI;
}
void Circle::translate(float tx, float ty){
}

Circle::~Circle(){}
