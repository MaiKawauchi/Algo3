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
<<<<<<< HEAD
    _num_items = 0;
    _allocated_size = 0;
    _items = nullptr;
  }

  // Copy constructor
  ArrayStack (const ArrayStack& copy){
    std::cout << "Copy constructor!" << std::endl;
    _items = new int[copy._num_items];
    _num_items = copy._num_items;
    _allocated_size = sizeof(_items);
    for(int i=0; i<_num_items; ++i){
      _items[i] = copy._items[i];
    }
  }

  // Destructor
  virtual ~ArrayStack (){
    delete[] _items;
  }

  // Copy assignment operator
  ArrayStack& operator = (const ArrayStack& ope){
    std::cout << "Assignment operator!" << std::endl;
    delete[] _items;
    _items = new int[ope._num_items];
    _allocated_size = sizeof(_items);
    _num_items = ope._num_items;
    for(int i=0; i<_num_items; ++i){
      _items[i] = ope._items[i];
    }
    return *this;
  }



  explicit ArrayStack(int allocated_size) : _items(new int[allocated_size])
  {
    _num_items = 0;
    _allocated_size = allocated_size;
=======
  _num_items = 0;
  _allocated_size = 0;
  _items = nullptr;
  /*
  ArrayStack(const ArrayStack& another_a)
    {
    _items = new int;
    *_items = *another_a.a;}
    */
  }
  explicit ArrayStack(int allocated_size) : _items(new int[allocated_size])
  {
    _num_items = 0;
    // _allocated_size = 0;
    //_items = new int;
    //*_items = allocated_size;
  }

  // Destructor::
  ~ArrayStack() {
    // COMPLETE
    delete[] _items;
>>>>>>> origin/master
  }

  void push(int item) {
    if (_num_items == _allocated_size) resize(2 * _allocated_size);
    _items[_num_items++] = item;
<<<<<<< HEAD
=======
    //    std::cout << item << std::endl;
>>>>>>> origin/master
  }

  int pop() {
    int ret = _items[--_num_items];
    std::cout << ret << std::endl;
    if (_num_items > 0 && _num_items == _allocated_size/4) resize(_allocated_size/2);
    return ret;
  }

  bool empty() const { return _num_items == 0; }

  int size() const { return _num_items; }
<<<<<<< HEAD
}; // class ArrayStack};
=======
};
>>>>>>> origin/master

#endif // ARRAY_STACK_H
