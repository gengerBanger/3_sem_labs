//
// Created by aleks on 06.10.2023.
//

#include "DynamicArr.h"
#include <iostream>

DynamicArray::DynamicArray(int & capacity) : size(0){
    this->capacity = capacity;
    array = new int[capacity];
}
DynamicArray::DynamicArray() : size(0){
    this->capacity = 32;
    array = new int[capacity];
}
DynamicArray::~DynamicArray(){
    //delete[] array;
}
void DynamicArray::push_back(int value) {
    if(size == capacity){
        capacity *= 2;
        int* newArray = new int[capacity];
        for(int i = 0; i < size; i++){
            newArray[i] = array[i];
        }
        delete[] array;
        array = newArray;
    }
    array[size++] = value;
}

void DynamicArray::insert(int pos, int value) {

    if(pos < 0 || pos > size){
        std::cout << "Invalid position for insertion" << std::endl;
    }

    if(size == capacity){
        capacity *= 2;
        int* newArray = new int[capacity];
        for(int i = 0; i < size; i++){
            newArray[i] = array[i];
        }
        delete[] array;
        array = newArray;
    }

    for(int i = size; i > pos; i--){
        array[i] = array[i - 1];
    }
    array[pos] = value;
    size++;
}



void DynamicArray::remove(int pos){
    if(size == 1){
        delete[] array;
        array = nullptr;
    }
    else{
        for(int i = pos; i < size - 1; i++){
            array[i] = array[i + 1];
        }
        size--;
        int * temp = new int[size];
        for (int i = 0; i < size; ++i) {
            temp[i] = array[i];
        }
        delete[] array;
        array = temp;
    }
}



void DynamicArray::swap(int pos1, int pos2){

    if(pos1 >= 0 && pos1 < size && pos2 >= 0 && pos2 < size){
        int temp = array[pos1];
        array[pos1] = array[pos2];
        array[pos2] = temp;
    }
    else{
        std::cout << "Index out of bounds" << std::endl;
    }
}

void DynamicArray::print() const {

    for(int i = 0; i < size; i++){
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

int DynamicArray::GetCapacity() {
    return capacity;
}

int DynamicArray::GetSize() {
    return size;
}
void DynamicArray :: SetSize(int new_size){
    size = new_size;
}

int * DynamicArray::GetArray() {
    return array;
}
int & DynamicArray ::  operator[](int index){
    return array[index];
}

void DynamicArray::clear() {
    size = 0;
    capacity = 32;
    int * newArray = new int[capacity];
    delete[] array;
    array = newArray;
}
