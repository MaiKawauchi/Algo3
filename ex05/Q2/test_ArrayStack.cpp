// test_ArrayStack.cpp
#include "ArrayStack.h"

int main(void)
{
  /*------------------------------------------------------------*/
  // stack1
  /*------------------------------------------------------------*/
  ArrayStack stack1;
  for(int i=1; i<=5; i++) stack1.push(i);

  /*------------------------------------------------------------*/
  // stack2
  /*------------------------------------------------------------*/

  ArrayStack stack2(5);
  for(int i=1; i<=10; i++) stack2.push(i);

  /*------------------------------------------------------------*/
  // stack3, stack4
  /*------------------------------------------------------------*/
  ArrayStack stack3(stack1); // calls the default copy ctor

  ArrayStack stack4 = stack2; // calls the default copy ctor


  /*------------------------------------------------------------*/
  // stack5, stack6
  /*------------------------------------------------------------*/
  ArrayStack stack5;
  stack5 = stack1;

  ArrayStack stack6(10);
  stack6 = stack6;



  /* pop */
  std::cout << "[stack1]" << std::endl;
  while(stack1.empty() != 1 ){
    stack1.pop();
  }
  std::cout << "[stack2]" << std::endl;
  while(stack2.empty() != 1 ){
    stack2.pop();
  }
  std::cout << "[stack3]" << std::endl;
  while(stack3.empty() != 1 ){
    stack3.pop();
  }
  std::cout << "[stack4]" << std::endl;
  while(stack4.empty() != 1 ){
    stack4.pop();
  }
  std::cout << "[stack5]" << std::endl;
  while(stack5.empty() != 1 ){
    stack5.pop();
  }
  std::cout << "[stack6]" << std::endl;
  while(stack6.empty() != 1 ){
    stack6.pop();
  }

  return 0;
}
