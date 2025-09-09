#include <iostream>
#include <array>
#include <math.h>
#include <algorithm>
#include "array.h"

void swapNumbers(int *num1, int *num2){
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

void printIntArray(int *arr, const int &size){
    for(int i = 0; i < size; i++){
        std::cout << arr[i] << " ";
    }
}

void printStringArray(std::string *arr, const int &size){
    for(int i = 0; i < size; i++){
        std::cout << "Element-" << arr[i] << std::endl;
    }
}

int* getArrayInput(int *arr, const int &size){
    int input;
    for(int i = 0; i != size; i++) {
        std::cout << "Enter a number to enter into the array (If done, enter EOF or any string): ";
        std::cin >> input;
        arr[i] = input;
    }
    std::cin.clear();
    std::cin.ignore();
    return arr;
}

int* sumOddEven(int arr[], const int &size){
    if(size == 0) return nullptr;
    static int result[2];
                                                     // Sum of Even and Odd Numbers
    for(int i = 0; i < size; i++){
        arr[i] % 2 == 0 ? result[0] += arr[i] : result[1] += arr[i];
    }
    return result;
}

int linearSearchArray(const int *arr, const int &size, int target){
    for(int i = 0; i < size; i++){
        if(arr[i] == target) return i;
    }
    return -1;
}

int binarySearchArray(int* arr, const int &size, int target){
    std::sort(arr, arr + size);
    int start = 0, end = size - 1, mid = start + (end - start) / 2;
    while(start <= end){
        mid = start + (end - start) / 2;
        if(target == arr[mid]) return mid;
        if(target > arr[mid]){
            start = mid;
        }
        if(target < arr[mid]){
            end = mid;
        }
    }
    return mid;
}

int largestElementArray(int* arr, const int &size, int limit = 0){
    if(limit == 0) limit = size;
    if(limit < 0) return -69;
    if(limit > size){
        std::cout << "You may be an idiot." << std::endl;
        return -69;
    }
    std::partial_sort(arr, arr + limit, arr + size, std::greater<int>());
    return arr[limit - 1];
}

int smallestElementArray(int* arr, const int &size, int limit = 0){
    if(limit == 0) limit = size;
    if(limit < 0) return -69;
    if(limit > size){
        std::cout << "You may be an idiot." << std::endl;
        return -69;
    }
    std::partial_sort(arr, arr + limit, arr + size, std::less<int>());
    return arr[limit - 1];
}

void elementsAtLeastTwoSignificantNeighbors(int* arr, const int &size){
    std::cout << "Elements which have at-least two greater elements: ";
    for(int i = 0; i < size; i++){
        int counter = 0;
        for(int j = 0; j < size; j++){
            if(arr[j] > arr[i]) counter++;
        }
        if(counter >= 2) std::cout << arr[i] << " ";
    }
}

void nextGreaterElementForEveryElement(int *arr, const unsigned int &size){
    for(int i = 0; i < size; i++){
        for(int j = i+1; j < size; j++){
            if(arr[j] > arr[i]){
                std::cout << "The next greater element of " << arr[i] << " is " << arr[j] << std::endl;
                break;
            }
        }
    }
}

void optNextGreaterElementForEveryElement(int *arr, const unsigned int &size){
    int stack[size];
    int top = -1;

    int result[size];
    for(unsigned int i = 0; i < size; i++) result[i] = -1;
    for(unsigned int i = 0; i < size; i++){
        while(top != -1 && arr[i] > arr[stack[top]]){
            result[stack[top]] = arr[i];
            top--;
        }
        stack[++top] = i;
    }

    for(unsigned int i = 0; i < size; i++){
        if(result[i] == -1) std::cout << "The next greater element of " << arr[i] << " does not exist!" << std::endl;
        else std::cout << "The next greater element of " << arr[i] << " is " << result[i] << std::endl; 
    }
}

void waveFormSortingArray(int *arr, const unsigned int &size){
    std::sort(arr, arr + size);

    for(int i = 0; i < size - 1; i += 2){
        swapNumbers(&arr[i], &arr[i+1]);
    }
}

int *sortArray(int *arr, const unsigned int &size){
    std::sort(arr, arr + size);
    return arr;
}

void reverseArray(int *arr, const unsigned int &size){
    int st = 0, end = size - 1, temp = -1;
    
    while(st <= end){
        temp = arr[st];
        arr[st] = arr[end];
        arr[end] = temp;
        st++; end--;
    }
}