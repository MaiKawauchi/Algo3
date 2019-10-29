#include <iostream>
#include "Rectangle.h"

using namespace std;

Rectangle::Rectangle(Point2D l, const float w, const float h)
  : left_corner(l)
  , width(w)
  , height(h){
}

string Rectangle::get_name()const{
  cout << "Rectangle" << endl;
  return "Rectangle";
}
float Rectangle::compute_area()const{
  return width * height;
}
void Rectangle::translate(float tx, float ty){
}

Rectangle::~Rectangle(){}
