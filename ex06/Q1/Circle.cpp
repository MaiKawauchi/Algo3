#include <iostream>
#include "Circle.h"

using namespace std;
extern const float PI;

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
  cout << endl;
  cout << "Circle: (" << center.x << ", " << center.y << ")" << endl;

  center.x += tx;
  center.y += ty;

  cout << "Circle translate: ("
       << center.x << ", " << center.y << ")" << endl;
}

Circle::~Circle(){}
