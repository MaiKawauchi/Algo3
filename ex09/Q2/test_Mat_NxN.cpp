#include <iostream>
#include <cassert>
#include "Mat_NxN.h"

using namespace std;

int main(void) {
  //int n;
  //  cin >> n; // NxN行列
  const int n=4;
  Mat_NxN<double, n> A; // A = I
  double coefficients[n][n] ={{1.0, 2.0, 3.0, 4.0}
                              ,{5.0, 6.0, 7.0, 8.0}
                              ,{9.0, 10.0, 11.0, 12.0}
                              ,{13.0, 14.0, 15.0, 16.0}};

  Mat_NxN<double, n> B(coefficients);

  Mat_NxN<double, n> C = A * B;
  assert(C == B);


  C += B;
  C -= A;

  assert(C(0,0) == 1.0);
  assert(C(1,1) == 11.0);
  assert(C(2,2) == 21.0);
  assert(C(3,3) == 31.0);

  Mat_NxN<double, n> D = -A; // OK

  assert(D(0,0) == -1.0);
  assert(D(1,1) == -1.0);
  assert(D(2,2) == -1.0);
  assert(D(3,3) == -1.0);

  cout << "Tests passed" << endl;

  return 0;
}
