#include "array.cpp"
#include <vector>
#include <iostream>

int searchRotatedSortedArray(const int *arr, const unsigned int &size, const int target){
    int st = 0, end = size - 1, mid = st + (end - st) / 2;

    while(st <= end){
        mid = st + (end - st) / 2;

        if(target == arr[mid]) return mid;
        if(arr[st] <= arr[mid]){
            if(target >= arr[st] && target <= arr[mid]) end = mid - 1;
            else st = mid + 1;
        } else{
            if(target >= arr[mid] && target <= arr[end]) st = mid + 1;
            else end = mid - 1;
        }
    }
    return -1;
}

int searchRotatedSortedArray(std::vector<int> &vec, const int target){
    int st = 0, end = vec.size() - 1, mid = st + (end - st) / 2;

    while(st <= end){
        mid = st + (end - st) / 2;

        if(target == vec[mid]) return mid;
        if(vec[st] <= vec[mid]){
            if(target >= vec[st] && target <= vec[mid]) end = mid - 1;
            else st = mid + 1;
        } else{
            if(target >= vec[mid] && target <= vec[end]) st = mid + 1;
            else end = mid - 1;
        }
    }
    return -1;
}

int main(){
    const unsigned int size = 8;
    int arr[size] {3,4,5,6,7,0,1,2};
    int target = 0;
    std::cout << searchRotatedSortedArray(arr, size, target);
    return 0;
}