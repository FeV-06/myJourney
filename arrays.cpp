#include <iostream>

void printArray(int arr[], int size){
    for(int i = 0; i < size; i++){
        std::cout << arr[i] << " ";
    }
}

int* sumOddEven(int arr[], int size){
    if(size == 0) return nullptr;
    static int result[2];
                                                     // Sum of Even and Odd Numbers
    for(int i = 0; i < size; i++){
        arr[i] % 2 == 0 ? result[0] += arr[i] : result[1] += arr[i];
    }
    return result;
}

int main(){
    int arr[] = {1,2,3,4,5,6,7,8};
    int *result = nullptr;
    int size = sizeof(arr) / sizeof(arr[0]);

    std::cout << "The array is: ";
    printArray(arr, size);
    std::cout << std::endl;

    result = sumOddEven(arr, size);
    std::cout << "The sum of odd numbers in the array: " << *(result) << "\nThe sum of odd numbers in the array: " << *(result + 1);
    return 0;
}