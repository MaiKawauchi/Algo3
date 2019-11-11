#include <iostream>
#include <cassert>
#include "Mat_NxN.h"

using namespace std;

int main(void) {
  int n;
  cin >> n; // NxN行列

  Mat_NxN<double, 4> A; // A = I
  double coefficients[4][4] ={{1.0, 2.0, 3.0, 4.0}
                              ,{5.0, 6.0, 7.0, 8.0}
                              ,{9.0, 10.0, 11.0, 12.0}
                              ,{13.0, 14.0, 15.0, 16.0}};
  Mat_NxN<double, 4> B(coefficients);

  Mat_NxN<double, 4> C = A * B; // OK
  assert(C == B);


  C += B; // OK
  C -= A; // OK

  // assert(C(0,0) == 1.0);
  // assert(C(1,1) == 9.0);
  //assert(C(2,2) == 17.0);

  Mat_NxN<double, 4> D = -A; // OK

  // assert(D(0,0) == -1.0);
  //assert(D(1,1) == -1.0);
  //assert(D(2,2) == -1.0);

  cout << "Tests passed" << endl;

  return 0;
}
