#include <iostream>
#include <sstream>
#include <functional>

using namespace std;

double deriv_fd(std::function<double(double)> f, double x) {
  double epsilon = 0.00000095367431640625;
  return (f(x+epsilon) - f(x-epsilon))/(2.0*epsilon);
}

double f(double x){return x*x;}

function<double(double)> deriv(std::function<double(double)> f)
{
  return [f](double x){ return  deriv_fd(f, x); };
}

int main(void) {
  auto df = deriv([](double x) { return x; });
  cout << df(1.0) << endl; // should be 1
  cout << df(2.0) << endl; // should be 1
}
