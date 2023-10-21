//
// Created by aleks on 20.10.2023.
//

#include "stack.h"
#include <iostream>
#include <Windows.h>
HANDLE hConsole;

void stack :: itemPush(DynamicArray array) {
    List_str * item = new List_str;
    if(curr == nullptr){
        curr = item;
        item->tail = nullptr;
    }
    else{
        item->tail = curr;
        curr = item;
    }
    item->stackArray = array;
}
DynamicArray stack ::itemOut() {
    if(!empty()){
        List_str ** buff = new List_str*(curr);
        DynamicArray buff_str;
        buff_str = curr->stackArray;
        curr = curr->tail;
        delete *buff;
        delete buff;
        return buff_str;
    }
    else {
        SetConsoleTextAttribute(hConsole, 12);
        std :: cout <<"Stack is empty"<<'\n';
        SetConsoleTextAttribute(hConsole, 10);
    }
}
void stack :: stackOut(){
    if(!empty()){
        List_str * buff = curr;
        while(buff){
            for(int i = 0; i < buff->stackArray.GetSize();i++) std :: cout << buff->stackArray[i] << " ";
            buff = buff->tail;
        }
        std :: cout << '\n';
    }
    else{
        SetConsoleTextAttribute(hConsole, 12);
        std :: cout <<"~~Stack is empty~~"<<'\n';
        SetConsoleTextAttribute(hConsole, 10);

    }
}
bool stack ::pairCheck() {
    if(!empty()){
        if(curr->tail != nullptr){
            return true;
        }
        else return false;
    }
    else return false;
}
stack :: ~stack(){
    while (curr){
        List_str * buff = curr;
        curr = curr->tail;
        delete [] buff->stackArray.GetArray();
        delete buff;
    }
}
List_str * stack :: GetCurr(){
    return curr;
}
bool stack :: empty(){
    if(!curr) return true;
    else return false;
}