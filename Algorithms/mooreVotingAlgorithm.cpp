#include "array.cpp"
#include <vector>
#include <iostream>

// int BF_majorityElement(const int *arr, const unsigned int size){ // O(n^2), the majority element relative to the other elements
//     int ans = -1, freq = 0, max = -static_cast<int>(INFINITY);
//     for(int i = 0; i < size; i++){
//         freq = 0;
//         for(int j = 0; j < size; j++){
//             if(arr[i] == arr[j]) freq++;
//         }
//         max = std::max(max, freq);
//         if(freq >= max) ans = arr[i];
//     }
//     return ans;
// }

int BF_majorityElement(const int *arr, const unsigned int &size){ // O(n^2), the majority element relative to the other elements and also greater than floor n / 2
    int ans = -1, freq = 0, max = -static_cast<int>(INFINITY);
    for(int i = 0; i < size; i++){  // assuming majority element exists always
        freq = 0;
        for(int j = 0; j < size; j++){
            if(arr[i] == arr[j]) freq++;
        }
        max = std::max(freq, max);
        if(freq > size/2){
            if(freq >= max) ans = arr[i];
        } 
    }
    return ans;
}



int main(){
    const unsigned int size = 3;
    int arr[size] {-3,2,-3};

    std::cout << BF_majorityElement(arr, size);
    return 0;
}