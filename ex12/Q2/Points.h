#ifndef _POINTS_H_
#define _POINTS_H_

#include <cmath>
#include <vector>
#include <queue>

using namespace std;

struct Point {
  Point()
    : x(0.0)
    , y(0.0)
    , z(0.0) {}

 Point(double x, double y, double z)
   : x(x)
   , y(y)
   , z(z) {}

 double x, y, z;
};

// k : positive integer
// P : a list of Points
vector<Point> find_k_closest(int k, vector<Point> P)
{
  // 処理順を表す比較関数オブジェクトにラムダ式を使用する
  auto Compare = [](const Point& f, const Point& s) -> bool
      {
      auto f_to_origin = sqrt(pow(f.x, 2) + pow(f.y, 2) + pow(f.z, 2));
      auto s_to_origin = sqrt(pow(s.x, 2) + pow(s.y, 2) + pow(s.z, 2));
      return f_to_origin > s_to_origin;
    };

    // doubleを要素に持つ優先順位付きキュー,比較関数オブジェクトを指定
    std::priority_queue<
      double,
      vector<Point>,
      decltype(Compare)
      > que {Compare};

    for(int i=P.size()-1; i>=0; --i){
      que.push(P[i]);
    }

    vector<Point> result;
    for(int i=0; i<k; i++){
      result.push_back(que.top());
      que.pop();
    }

  return result;
}


#endif
