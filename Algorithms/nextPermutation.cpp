#include "array.cpp"
#include <vector>
#include <iostream>

void nextPermutation(int *arr, const unsigned int &size){   // O(n) TC
    int pivot = -1;
    for(int i = size - 2; i >= 0; i--){
        if(arr[i] < arr[i+1]){
            pivot = i;
            break;
        }
    }
    if(pivot == -1) reverseArray(arr, size);

    for(int i = size - 1; i > pivot; i--){
        if(arr[i] > arr[pivot]){
            std::swap(arr[i], arr[pivot]);
            break;
        }
    }

    int st = pivot + 1, end = size - 1;
    while(st <= end){
        std::swap(arr[st], arr[end]);
        st++; end--;
    }


}

int main(){
    const unsigned int size = 6;
    int arr[size] {1,2,3,6,5,4};

    nextPermutation(arr, size);
    printIntArray(arr, size);
    return 0;
}