//
// Created by aleks on 16.10.2023.
//

#ifndef TIMSORT_TIMSORT_H
#define TIMSORT_TIMSORT_H
#include "DynamicArr.h"
#include "stack.h"
class TimSort {
private:
    static void insertSort(DynamicArray & runArray);
    static stack MergeProcess(stack sortedRuns);
    static void HollopMerger( List_str * x, List_str * y, List_str * z);
    static int GetMinrun(int n);
    static stack GetSubArray(DynamicArray & runArray);
public:
    static void timsort(DynamicArray & array);
};


#endif //TIMSORT_TIMSORT_H
