#include "array.cpp"
#include <vector>
#include <iostream>

int BF_singleElementSortedArray(const int *arr, const unsigned int &size){
    for(int i = 0; i < size; i++){
        if(i != 0){
            if(arr[i] != arr[i-1] && arr[i+1] != arr[i]) return arr[i];
        } else{
            if(arr[i] != arr[i+1]) return arr[i];
        }
    }
    return -1;
}

int BF_singleElementSortedArray(std::vector<int> &vec){
    for(int i = 0; i < vec.size(); i++){
        if(i != 0){
            if(vec[i] != vec[i-1] && vec[i+1] != vec[i]) return vec[i];
        } else{
            if(vec[i] != vec[i+1]) return vec[i];
        }
    }
    return -1;
}

int OPT_singleElementSortedArray(const int *arr, const unsigned int &size){
    int st = 0, end = size - 1, mid = st + (end - st) / 2;

    while(st <= end){
        mid = st + (end - st) / 2;

        if(arr[mid] == 0 && arr[mid] != arr[mid + 1]) return arr[mid];
        if(arr[mid] == size - 1 && arr[mid] != arr[mid - 1]) return arr[mid];

        if(arr[mid] != arr[mid - 1] && arr[mid] != arr[mid + 1]) return arr[mid];

        if(mid % 2 != 0){
            if(arr[mid] == arr[mid - 1]) st = mid + 1;
            else end = mid - 1;
        } else{
            if(arr[mid] == arr[mid - 1]) end = mid - 1;
            else st = mid + 1;
        }
    }
    return -1;
}

int OPT_singleElementSortedArray(std::vector<int> &vec){
    int st = 0, end = vec.size() - 1, mid = st + (end - st) / 2;

    while(st <= end){
        mid = st + (end - st) / 2;

        if(vec[mid] == 0 && vec[mid] != vec[mid + 1]) return vec[mid];
        if(vec[mid] == vec.size() - 1 && vec[mid] != vec[mid - 1]) return vec[mid];

        if(vec[mid] != vec[mid - 1] && vec[mid] != vec[mid + 1]) return vec[mid];

        if(mid % 2 != 0){
            if(vec[mid] == vec[mid - 1]) st = mid + 1;
            else end = mid - 1;
        } else{
            if(vec[mid] == vec[mid - 1]) end = mid - 1;
            else st = mid + 1;
        }
    }
    return -1;
}

int main(){
    const unsigned int size = 7;
    int arr[size] {3,3,7,7,10,11,11};
    std::vector<int> vec {3,3,7,7,10,11,11};
    std::cout << OPT_singleElementSortedArray(vec);
    return 0;
}