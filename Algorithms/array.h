#ifndef ARRAY_H
#define ARRAY_H

#include <string>

void swapNumbers(int *num1, int *num2);

void printIntArray(int *arr, const int &size);

void printStringArray(std::string *arr, const int &size);

int* getArrayInput(int *arr, const int &size);

int* sumOddEven(int arr[], const int &size);

int linearSearchArray(const int *arr, const int &size, int target);

int binarySearchArray(int* arr, const int &size, int target);

int largestElementArray(int* arr, const int &size, int limit);

int smallestElementArray(int* arr, const int &size, int limit);

void elementsAtLeastTwoSignificantNeighbors(int* arr, const int &size);

void nextGreaterElementForEveryElement(int *arr, const unsigned int &size);

void optNextGreaterElementForEveryElement(int *arr, const unsigned int &size);

void waveFormSortingArray(int *arr, const unsigned int size);


#endif