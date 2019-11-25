#include <vector>
#include <iostream>
#include "compute.h"
int main()
{
  vector<int> med;
  med.push_back(7);
  med.push_back(14);
  med.push_back(10);
  med.push_back(12);
  med.push_back(2);
  med.push_back(11);
  med.push_back(29);
  med.push_back(3);
  med.push_back(4);

  vector<double> closest = compute_k_closest(3, med);

  for (size_t i = 0; i < 3; ++i) {
   std::cout << closest[i] << std::endl;
 }

  cout << "--------------" << endl;
  vector<double> CLOSEST = COMPUTE_K_CLOSEST(3, med);
  std::cout << "The median is : " << COMPUTE_MEDIAN(med) << std::endl;
  // for (size_t i = 0; i < 3; ++i) {
    std::for_each(CLOSEST.begin(), CLOSEST.end(), [](int x)
                  {
                    std::cout << x << std::endl;
                  });
  return 0;
}
