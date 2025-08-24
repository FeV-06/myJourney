#include <iostream>
#include "array.cpp"

int main(){
    int arr[5] = {-1,-2,-3,4,-5};
    const unsigned int size = sizeof(arr) / sizeof(arr[0]);
    float max = -INFINITY;
    int sum;
    // std::cout << std::max(max, static_cast<float>(sum)) << std::endl;
    for(int i = 0; i < size; i++){
        sum = 0;
        for(int j = i; j < size; j++){
            sum += arr[j];
            max = std::max(max, static_cast<float>(sum));
        }
    }
    // max /= 2;
    std::cout << max;
    return 0;
}