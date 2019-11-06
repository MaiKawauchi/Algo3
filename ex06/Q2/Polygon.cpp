#include "Polygon.h"

using namespace std;

Polygon::Polygon(Point2D v, const int num_v)
  : vertices(v)
  , num_vertices(num_v){
}

string Polygon::get_name()const{
  return "Polygon";
}

float Polygon::compute_area()const{
  if(num_vertices < 3){ cout << "Please input 3 or more vertex." << endl;}
  //2 * Area = Sum_{i=0}^{N-1} x_i y_{i+1} - y_i x_{i+1}.
  return 5;
}

void Polygon::translate(float tx, float ty){
  cout << endl;
  cout << "Polygon: (" << vertices.x_i[0] << ", " << vertices.y_i[0] << ")" << endl;

  vertices.x_i[0] += tx;
  vertices.y_i[0] += ty;

  cout << "Polygon translate: ("
       << vertices.x_i[0] << ", " << vertices.y_i[0] << ")" << endl;
}

Polygon::~Polygon(){
  if (num_vertices > 0) {
    for (int i = 0; i < num_vertices; ++i){}
  }
}
