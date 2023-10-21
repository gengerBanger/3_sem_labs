//
// Created by aleks on 16.10.2023.
//

#ifndef TIMSORT_CONAPP_H
#define TIMSORT_CONAPP_H
#include <chrono>
#include <iostream>
#include "DynamicArr.h"
#include "TimSort.h"
class ConApp {
public:
    void createRandArray(DynamicArray & array);
    void CombSort (DynamicArray & arr);
    void exec();
};


#endif //TIMSORT_CONAPP_H
