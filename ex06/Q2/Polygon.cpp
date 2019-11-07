#include "Polygon.h"

using namespace std;

Polygon::Polygon(Point2D* v, const int num_v)
  : num_vertices(num_v){

  vertices.vertices = (Point2D*)malloc(sizeof(Point2D) * num_vertices);
  for(int i=0; i<num_vertices; ++i){
    vertices.vertices[i] = v[i];

  }
}

string Polygon::get_name()const{
  return "Polygon";
}

float Polygon::compute_area()const{
  if(num_vertices < 3){ cout << "Please input 3 or more vertex." << endl;}

  float area = 0.f;
  for (int i=0; i<num_vertices-1; ++i){

    area += vertices.vertices[i].x * vertices.vertices[i+1].y
      - vertices.vertices[i].y * vertices.vertices[i+1].x;
  }
  area += vertices.vertices[num_vertices-1].x * vertices.vertices[0].y
    - vertices.vertices[num_vertices-1].y * vertices.vertices[0].x;
  area *= 0.5f;

  return area;
}

void Polygon::translate(float tx, float ty){
  cout << endl;
  cout << "Polygon: (" << vertices.vertices->x
       << ", "<< vertices.vertices->y << ")" << endl;

  vertices.vertices->x_i[0] += tx;
  vertices.vertices->y_i[0] += ty;

  cout << "Polygon translate: ("<< vertices.vertices->x_i[0]
       << ", " << vertices.vertices->y_i[0] << ")" << endl;
}

Polygon::~Polygon(){}
