#ifndef _RAN_H
#define _RAN_H_

#include <iostream>
#include <vector>

struct Nocase{
    int num;
    Nocase(int inputted_num){
        num = inputted_num;
    }
};

template <class Ran>
void sort(Ran begin, Ran end);


#endif
