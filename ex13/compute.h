#ifndef _COMPUTE_H_
#define _COMPUTE_H_

#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;

/*-----------------------------------------------------------*/
vector<double> compute_k_closest(int k, std::vector<int> n)
{
  double median;
  std::sort(n.begin(), n.end());
  if (n.size() % 2 == 1) {
    median = n[(n.size() - 1) / 2];
  } else {
    median = (n[(n.size() / 2) - 1] + n[n.size() / 2]) / 2;
  }

  cout << "The median is : " << median << endl;

  auto compute_median = [median](int lhs, int rhs) -> bool
    {
      return abs(lhs - median) > abs(rhs - median);
    };

  std::priority_queue<
    double,
    vector<int>,
    decltype(compute_median)
    > que {compute_median};

  for(int i=n.size()-1; i>=0; --i){
    que.push(n[i]);
  }

  vector<double> result;
  for(int i=0; i<k; i++){
    result.push_back(que.top());
    que.pop();
  }

  return result;
}




/*-----------------------------------------------------------*/
double COMPUTE_MEDIAN(const vector<int>& n){
  auto tmp = n;
  const auto tmpSize = tmp.size()/2;
  std::nth_element(tmp.begin(), tmp.begin() + tmpSize, tmp.end());

  if(tmp.size() %2 == 0){
    return (tmp[tmpSize - 1] + tmp[tmpSize]) * 0.5;
  }
  return (tmp[tmpSize]);
}


vector<double> COMPUTE_K_CLOSEST(int k, const vector<int>& n)
{
  auto median = COMPUTE_MEDIAN(n);
  auto tmp = n;

  auto compare = [median](int lhs, int rhs){
    auto l = abs(lhs - median);
    auto r = abs(rhs - median);
    return l < r;
  };

  std::nth_element(tmp.begin(), tmp.begin() + n.size()/2, tmp.end(), compare);

  return vector<double>(tmp.begin(), tmp.begin()+k);
}



#endif
