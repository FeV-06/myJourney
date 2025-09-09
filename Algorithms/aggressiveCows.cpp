#include <iostream>
#include <algorithm>
#include <vector>

bool isValid(int *arr, const unsigned int &size, const unsigned int &maxCows, const int &minAllowedDistance){
    int cows = 1, lastStallPos = arr[0];
    
    std::sort(arr, arr+size);
    for(int i = 1; i < size; i++){
        if(arr[i] - lastStallPos >= minAllowedDistance){
            cows++;
            lastStallPos = arr[i];
        }
        if(cows == maxCows) return true;
    }
    return false;
}

int aggressiveCows(int *arr, const unsigned int &size, const unsigned int &maxCows){
    if(maxCows > size) return -1;

    int low = 1, high = 0;
    for(int i = 0; i < size; i++){
        high += arr[i];
    }
    
    int st = low, end = high, mid = st + (end - st) / 2, ans = -1;
    while(st <= end){
        mid = st + (end - st) / 2;

        if(isValid(arr, size, maxCows, mid)){
            ans = mid;
            st = mid + 1;
        }else{
            end = mid - 1;
        }
    }
    return ans;
}

int main(){
    const unsigned int size = 5;
    const unsigned int maxCows = 3;
    int arr[size] {1,2,8,4,9};

    std::cout << aggressiveCows(arr, size, maxCows);
    return 0;
}