#include "array.cpp"
#include <vector>
#include <iostream>

void bubbleSort(int *arr, const unsigned int &size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[i])
            {
                std::swap(arr[i], arr[j]);
            }
        }
    }
}

void selectionSort(int *arr, const unsigned int &size){
    int min = 999999;
    int idx = 0;
    for(int i = 0; i < size - 1; i++){
        min = 999999;
        for(int j = i; j < size; j++){
            min = std::min(arr[j], min);
        }
        idx = linearSearchArray(arr, size, min);
        std::swap(arr[idx], arr[i]);
    }
}

void insertionSort(int *arr, const unsigned int &size){
    int curr, prev;
    for(int i = 1; i < size; i++){
        curr = arr[i];
        prev = i-1;
        
        while(prev >= 0 && arr[prev] > curr){
            arr[prev + 1] = arr[prev];
            prev--;
        }
        arr[prev+1] = curr;
    }
}

int main()
{
    const unsigned int size = 6;
    int arr[size]{1, 5, 3, 6, 2, 10};
    insertionSort(arr, size);
    printIntArray(arr, size);
    return 0;
}