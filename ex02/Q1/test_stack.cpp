// test_stack.cpp

#include <iostream>
#include <cassert>
#include "stack.h"

int main(void) {
  Stack stack(100);

  /* first Stack check */
  if (stack.empty()) std::cout << "Stack is empty." << std::endl;
  else std::cout << "Stack is not empty." << std::endl;

  /* 要素を追加 */
  for (int i = 0; i < 40; ++i) {
    stack.push(i);
  }

  /* second Stack check */
  if (stack.empty()) std::cout << "Stack is empty." << std::endl;
  else std::cout << "Stack is not empty." << std::endl;

  assert(stack.full() == false); // stack.full()は、falseでなければならない

  int i = 39;
  while (!stack.empty()) {
    int element = stack.top();
     assert(element == i); //elementは、iでなければならない
    stack.pop();
    i = i - 1;
  }

  return 0;
}
