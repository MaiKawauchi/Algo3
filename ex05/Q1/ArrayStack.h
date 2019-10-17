// ArrayStack.h

#include <string>
#include <iostream>

#ifndef ARRAY_STACK_H
#define ARRAY_STACK_H

class ArrayStack {
private:
  int _num_items; // number of items in the stack
  int* _items; // stack items
  int _allocated_size; // size of memory allocated

  void resize(int max_size) {
    if (max_size==0) max_size++;

    // Move stack to a new array of size max
    _allocated_size = max_size;
    int* temp = new int[max_size];
    // Copy
    for (int i = 0; i < _num_items; ++i) {
      temp[i] = _items[i];
    }
    delete[] _items;
    _items = temp;
  }

public:
  // Constructors:
  ArrayStack()
  {
  _num_items = 0;
  _allocated_size = 0;
  _items = NULL;
  }

  explicit ArrayStack(int allocated_size) : _items(new int[allocated_size])
  {
    _num_items = 0;
    allocated_size = _num_items;
  }

  // Destructor::
  ~ArrayStack() {
    // COMPLETE
    delete[] _items;
  }

  void push(int item) {
    if (_num_items == _allocated_size) resize(2*_allocated_size);
    _items[_num_items++] = item;
    std::cout << item << std::endl;
  }

  int pop() {
    int ret = _items[--_num_items];
    if (_num_items > 0 && _num_items == _allocated_size/4) resize(_allocated_size/2);
    return ret;
  }

  bool empty() const { return _num_items == 0; }

  int size() const { return _num_items; }
};

#endif // ARRAY_STACK_H
