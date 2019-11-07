#ifndef MYPAIR_H
#define MYPAIR_H

#include <iostream>
#include <utility>
#include <cstring>


template<class T1, class T2>
class MyPair{

public:
  MyPair(const T1 f, const T2 s)
    : first(f)
    , second(s){
  }

  T1 first;
  T2 second;

};

#endif
