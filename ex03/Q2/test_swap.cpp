// test_swap.cpp

// <- Include all the necessary headers here
#include <cassert>
#include <iostream>
#include "swap.h"

int main(void) {
  int i = 1;
  int j = 2;

  std::cout << "Before swap" << std::endl;
  std::cout << " i = " << i << ", "
            << " j = " << j << std::endl;

  /* call swap() in order to swap the contents of i and j;
     pass the arguments to swap by reference. */
  Swap1(i, j);

  assert(i == 2);
  assert(j == 1);

  std::cout << "After 1st swap" << std::endl;
  std::cout << " i = " << i << ", "
            << " j = " << j << std::endl;


  /* call swap() here in order to swap the contents of i and j;
     pass the arguments by pointers.
  */
  Swap2(&i, &j);
  assert(i == 1);
  assert(j == 2);

  std::cout << "After 2nd swap" << std::endl;
  std::cout << " i = " << i << ", "
            << " j = " << j << std::endl;

  return 0;
}
