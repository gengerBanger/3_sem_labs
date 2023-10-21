//
// Created by aleks on 16.10.2023.
//

#include "TimSort.h"
#include "stack.h"
#include <iostream>
#include <cmath>

void TimSort::timsort(DynamicArray &array){
    std :: cout << " >>> Sorted array :\n\n";
    if(array.GetSize() <= 64){
        insertSort(array);
        array.print();
    }
    else MergeProcess(GetSubArray(array)).stackOut();
}

void TimSort::insertSort(DynamicArray &runArray) {
    for (int i = 1; i < runArray.GetSize(); i++) {
        for (int j = i; j > 0; j--) {
            if (runArray[j] < runArray[j - 1])
                std::swap(runArray[j], runArray[j - 1]);
        }
    }
}

int TimSort::GetMinrun(int n) {
    int r = 0;
    while (n >= 64) {
        r |= n & 1;
        n >>= 1;
    }
    return n + r;
}

stack TimSort::GetSubArray(DynamicArray &array) {
    int minrun = GetMinrun(array.GetSize());
    stack sortedRuns;
    for (int i = 0; i < array.GetSize() - 1; i++) {
        DynamicArray run;
        run.push_back(array[i++]);
        if (array[i] <= array[i + 1]) while (array[i] <= array[i + 1] && i < array.GetSize() - 1) run.push_back(array[i++]);
        else while (array[i] > array[i + 1] && i < array.GetSize() - 1)run.push_back(array[i++]);
        while (run.GetSize() < minrun && i < array.GetSize()) {
            run.push_back(array[i++]);
        }
        i--;
        insertSort(run);
        sortedRuns.itemPush(run);
    }
    return sortedRuns;
}
int binarySearchHollop(DynamicArray &arr, int target) {
    int left = 0;
    int right = arr.GetSize() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid;
        }
        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}
stack TimSort::MergeProcess(stack sortedRuns) {
    stack mergedSortedRuns ;
    while(sortedRuns.GetCurr()) mergedSortedRuns.itemPush(sortedRuns.itemOut());
    List_str * buffCur = mergedSortedRuns.GetCurr();
    while(buffCur->tail->tail){
        List_str * x = buffCur;
        List_str *  y = buffCur->tail;
        List_str *  z = buffCur->tail->tail;
        if (x->stackArray.GetSize() + y->stackArray.GetSize() > z->stackArray.GetSize() ||
        y->stackArray.GetSize() < x->stackArray.GetSize()) HollopMerger( x, y, z);
    }
    DynamicArray buffer;
    int sizeOfBuffer = buffCur->stackArray.GetSize();
    for (int i = 0; i < sizeOfBuffer; i++) {
        buffer.push_back(buffCur->stackArray[i]);
    }
    buffCur->stackArray.clear();
    int i = 0, j = 0;
    while(i < sizeOfBuffer && j < buffCur->tail->stackArray.GetSize()){
        if(buffer[i] > buffCur->tail->stackArray[j]){
            buffCur->stackArray.push_back(buffCur->tail->stackArray[j]);
            j++;
        }
        else{
            buffCur->stackArray.push_back(buffer[i]);
            i++;
        }
    }
    for(; i < sizeOfBuffer;i++) buffCur->stackArray.push_back(buffer[i]);
    for(; j < buffCur->tail->stackArray.GetSize();j++) buffCur->stackArray.push_back(buffCur->tail->stackArray[j]);
    buffCur->tail = nullptr;
    delete buffCur->tail;
    return mergedSortedRuns;
}

void TimSort::HollopMerger( List_str * x, List_str * y, List_str * z){
    DynamicArray buffer;
    int sizeOfBuffer;
    int HollopCounterY = 0, HollopCounterBuffer = 0;
    if (x->stackArray.GetSize() <= z->stackArray.GetSize()) { // x
            sizeOfBuffer = x->stackArray.GetSize();
            for (int i = 0; i < sizeOfBuffer; i++) {
                buffer.push_back(x->stackArray[i]);
            }
            x->stackArray.clear();
            int i = 0, j = 0;
            while(i < sizeOfBuffer && j < y->stackArray.GetSize()){
                if(buffer[i] > y->stackArray[j]){
                    x->stackArray.push_back(y->stackArray[j]);
                    j++;
                    HollopCounterY++;
                    HollopCounterBuffer = 0;
                    if(HollopCounterY == 7)binarySearchHollop(x->stackArray, j);
                }
                else{
                    x->stackArray.push_back(buffer[i]);
                    i++;
                    HollopCounterBuffer++;
                    HollopCounterY = 0;
                    if(HollopCounterBuffer == 7)binarySearchHollop(x->stackArray, i);
                }
            }
        for(; i < sizeOfBuffer;i++) x->stackArray.push_back(buffer[i]);
        for(; j < y->stackArray.GetSize();j++) x->stackArray.push_back(y->stackArray[j]);
            x->tail = x->tail->tail;
            delete y;
    } else
    { // z
            sizeOfBuffer = z->stackArray.GetSize();
            for (int i = 0; i < sizeOfBuffer; i++) {
                buffer.push_back(z->stackArray[i]);
            }
            z->stackArray.clear();
            int i = 0, j = 0;
            while(i < sizeOfBuffer && j < y->stackArray.GetSize()){
                if(buffer[i] > y->stackArray[j]){
                    z->stackArray.push_back(y->stackArray[j]);
                    j++;
                    HollopCounterY++;
                    HollopCounterBuffer = 0;
                    if(HollopCounterY == 7)binarySearchHollop(x->stackArray, j);
                }
                else{
                    z->stackArray.push_back(buffer[i]);
                    i++;
                    HollopCounterBuffer++;
                    HollopCounterY = 0;
                    if(HollopCounterBuffer == 7)binarySearchHollop(x->stackArray, i);
                }
            }
        for(; i < sizeOfBuffer;i++) z->stackArray.push_back(buffer[i]);
        for(; j < y->stackArray.GetSize();j++) z->stackArray.push_back(y->stackArray[j]);
            x->tail = x->tail->tail;
            delete y;
    }
}
