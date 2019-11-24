#include <iostream>
#include <vector>

#include "Points.h"
using namespace std;

int main(void) {
 vector<Point> points;
 points.push_back(Point(1.0,2.0,3.0));
 points.push_back(Point(5.0,5.0,5.0));
 points.push_back(Point(0.0,2.0,1.0));
 points.push_back(Point(9.0,2.0,1.0));
 points.push_back(Point(1.0,2.0,1.0));
 points.push_back(Point(2.0,2.0,1.0));

 vector<Point> closest = find_k_closest(3, points);

 for (size_t i = 0; i < 3; ++i) {
   std::cout << closest[i].x << "," << closest[i].y << ","
             << closest[i].z << std::endl;
 }

 return 0;
}
