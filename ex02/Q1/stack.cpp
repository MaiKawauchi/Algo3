#include <iostream>
#include "stack.h"


// check whether the stack is empty
bool Stack::empty()
{
  //std::cout << _top << std::endl;
  if(_top <= 0) return true;
  else return false;
}

// check whether the stack is full
bool Stack::full()
{
  if(_top == _max_size) return true;
  else return false;
}

// return the number of elements
int Stack::size()
{
  return _top;
}

// insert element on top
// print an error message on std::cerr when overflow
void Stack::push(int n)
{
  if(_top == sizeof(_data) / sizeof(_data[0]) - 1){
    //std::cout << n << std::endl;
    ++_top;
  }else{
    _data[++_top] = n;
  }
}

// remove element on top
// print an error message on std::cerr when underflow
void Stack::pop()
{
  if(_top == 0){
    std::cout << "Error : Stack is EMPTY!" << std::endl;
  }else{
    --_top;
  }
}

// acces the topmost element
int Stack::top(){
  return _data[_top];
}
