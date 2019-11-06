#ifndef Polygon_h
#define Polygon_h

#include <iostream>
#include "Shape2D.h"

using namespace std;

class Polygon : public Shape2D{
public:
  Polygon();
  Polygon(Point2D vertices, const int NUM_VERTICES);
  string get_name()const override;
  float compute_area()const override;
  void translate(float tx, float ty) override;

  ~Polygon();

private:
  Point2D vertices;
  int num_vertices;
};

#endif // Polygon_h
