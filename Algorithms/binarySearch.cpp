#include <iostream>
#include "array.cpp"
#include <vector>

int binarySearch(int *arr, const unsigned int &size, const int &target){
    arr = sortArray(arr, size);
    std::cout << "Modified Array after sorting: ";
    printIntArray(arr, size);
    std::cout << '\n';
    int st = 0, end = size - 1, mid = end + (st - end) / 2;


    while(st <= end){
        mid = end + (st - end) / 2;

        if(arr[mid] == target) return mid;
        if(target > arr[mid]) st = mid + 1;
        if(target < arr[mid]) end = mid - 1;
    }
    return -1;
}

int main(){
    const unsigned int size = 5;
    int arr[size] {2,5,11,7,13};
    std::cout << "Original Array: ";
    printIntArray(arr, size);
    std::cout << '\n';
    int target = 11;
    int idx = binarySearch(arr, size, target);
    std::cout << "The index of the target in the modified array is: " << idx;
    return 0;
}