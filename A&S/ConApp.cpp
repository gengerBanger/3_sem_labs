//
// Created by aleks on 16.10.2023.
//

#include "ConApp.h"
void ConApp :: createRandArray(DynamicArray & array) {
    srand(time(nullptr));
    for (int i = 0; i < array.GetCapacity();i++){
        array.GetArray()[i] = rand() % 2001 - 1000;
        array.SetSize(array.GetSize() + 1);
    }
}
void ConApp:: CombSort (DynamicArray & arr){
    int s = arr.GetSize() - 1;
    while (s >= 1){
        for (int i = 0; i + s < arr.GetSize(); i++)
            if (arr[i] > arr[i + s]) std :: swap(arr[i], arr[i + s]);
        s--;
    }

}
void ConApp::exec() {
    bool run = true;
    int sizeOfArray;
    int type;
    while (run){
        std :: cout << "~~~Enter the amount of elements~~~\n--->";
        std :: cin >> sizeOfArray;
        DynamicArray mainArray(sizeOfArray);
        createRandArray(mainArray);
        std :: cout << " >>> Unsorted array :\n\n";
        mainArray.print();
        std :: cout << "~~~Choose the type of sort~~~\n\n1) TimSort\n\n2) CombSort\n\n3) Exit\n--->";
        std :: cin >> type;
        switch (type) {
            case 1:{
                TimSort::timsort(mainArray);
                break;
            }
            case 2:{
                CombSort(mainArray);
                mainArray.print();
                break;
            }
            case 3:{
                run = false;
            }
        }
        getchar();
        std :: cin.get();
        system("cls");
    }
}



