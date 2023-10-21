//
// Created by aleks on 06.10.2023.
//

#ifndef LAB_1_ALG_DARR_H
#define LAB_1_ALG_DARR_H
class DynamicArray{

private:
    int * array;
    int capacity;
    int size;

public:
    DynamicArray(int & capacity);
    DynamicArray();
    ~DynamicArray();

    void push_back(int value);
    void insert(int pos, int value);
    void remove(int pos);
    void clear();
    void swap(int pos1, int pos2);
    void print() const;
    int GetCapacity();
    int * GetArray();
    int GetSize();
    void SetSize(int new_size);
    int & operator[](int index);
};

#endif //LAB_1_ALG_DARR_H
