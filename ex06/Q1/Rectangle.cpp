#include <iostream>
#include "Rectangle.h"

using namespace std;

Rectangle::Rectangle(Point2D l, const float w, const float h)
  : left_corner(l)
  , width(w)
  , height(h){
}

string Rectangle::get_name()const{
  return "Rectangle";
}
float Rectangle::compute_area()const{
  return width * height;
}
void Rectangle::translate(float tx, float ty){
  cout << endl;
  cout << "Rectangle: (" << left_corner.x << ", " << left_corner.y << ")" << endl;

  left_corner.x += tx;
  left_corner.y += ty;

  cout << "Rectangle translate: ("
       <<left_corner.x << ", " << left_corner.y << ")" << endl;
}

Rectangle::~Rectangle(){}
