//
// Created by aleks on 20.10.2023.
//

#ifndef TIMSORT_STACK_H
#define TIMSORT_STACK_H
#include <iostream>
#include "DynamicArr.h"

struct List_str;
class stack{
private:
    List_str * curr = nullptr;
public:
    void itemPush(DynamicArray array);
    DynamicArray itemOut();
    void stackOut();
    bool pairCheck();
    ~stack();
    List_str * GetCurr();
    bool empty();
};
struct List_str{
    DynamicArray stackArray;
    List_str * tail;
};

#endif //TIMSORT_STACK_H
