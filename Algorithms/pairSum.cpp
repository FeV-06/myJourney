#include "array.cpp"
#include <iostream>

void pairSum(const int *arr, const unsigned int &size, const int &target){ // O(n^2), also not limited to just one pair in an array
    for(int i = 0; i < size; i++){
        for(int j = i + 1; j < size; j++){
            if(arr[i] + arr[j] == target) std::cout << "The indices of the pairs that matches the target: (" << i << ", " << j << ")\n"; 
        }
    }
}



int main(){
    return 0;
}