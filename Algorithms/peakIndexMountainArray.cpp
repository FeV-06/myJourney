#include "array.cpp"
#include <vector>
#include <iostream>

int BF_peakIndexMountainArray(const int *arr, const unsigned int &size){    // O(n) TC
    for(int i = 1; i < size - 1; i++){
        if(arr[i] > arr[i-1] && arr[i] > arr[i+1]) return i;
    }
    return -1;
}

int OPT_peakIndexMountainArray(const int *arr, const unsigned int &size){
    int st = 1, end = size - 2, mid = st + (end - st) / 2;

    while(st <= end){
        mid = st + (end - st) / 2;

        if(arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1]) return mid;

        if(arr[mid] > arr[mid - 1] && arr[mid] < arr[mid + 1]) st = mid + 1;
        else end = mid - 1;
    }
    return -1;
}

int main(){
    const unsigned int size = 3;
    int arr[size] {1,2,1};

    std::cout << OPT_peakIndexMountainArray(arr, size);
    return 0;
}