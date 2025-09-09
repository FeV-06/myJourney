// Dutch National Flag Algorithm
#include "array.cpp"
#include <vector>
#include <iostream>

void BF_dnfSort(int *arr, const unsigned int &size){    // O(nlogn) TC
    std::sort(arr, arr + size);
}

void OPT_dnfSort(int *arr, const unsigned int &size){   // O(n) TC
    int countZeros = 0, countOnes = 0, countTwos = 0;

    for(int i = 0; i < size; i++){
        if(arr[i] == 0) countZeros++;
        else if(arr[i] == 1) countOnes++;
        else countTwos++;
    }

    for(int i = 0; i < countZeros; i++) arr[i] = 0;
    for(int i = countZeros; i < countZeros + countOnes; i++) arr[i] = 1;
    for(int i = countZeros + countOnes; i < size; i++) arr[i] = 2;
}

void dnfSort(int *arr, const unsigned int &size){
    int mid = 0, low = 0, high = size - 1;

    while(mid <= high){
        if(arr[mid] == 0){
            std::swap(arr[mid], arr[low]);
            mid++;
            low++;
        } else if(arr[mid] == 1) mid++;
        else{
            std::swap(arr[mid], arr[high]);
            high--;
        }
    }
}

int main(){
    const unsigned int size = 9;
    int arr[size] {2,1,2,2,0,1,0,0,1};

    dnfSort(arr, size);
    printIntArray(arr, size);
    return 0;
}