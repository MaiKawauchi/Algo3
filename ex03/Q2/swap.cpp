#include <iostream>
using std::swap;

void Swap1(int &i, int &j)
{
  // swap(i, j);
  int temp;
  temp = i;
  i = j;
  j = temp;
}

void Swap2(int* i, int* j)
{
  int temp;
  temp = *i;
  *i = *j;
  *j = temp;
}
