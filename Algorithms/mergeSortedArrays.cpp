#include "array.cpp"
#include <vector>
#include <iostream>

void BF_mergeSortedArrays(int *arr1, const unsigned int &s1, int *arr2, const unsigned int &s2)
{
    int countZeros = 0, idx = 0; bool first = false;
    for (int i = 0; i < s1; i++)
    {
        if (arr1[i] == 0)
        {
            if(!first){
                first = true;
                idx = i;
            } 
            countZeros++;
        }
    }
    
    if(countZeros != s2){
        std::cout << "The available spaces in the first array has to be equal to the amount of elements in the second array.\n";
        return;
    }
    
    int st = 0;
    for (int i = idx; i < s1 + s2 - countZeros; i++)
    {
        arr1[i] = arr2[st];
        st++;
    }
    std::sort(arr1, arr1 + s1);
}

int OPT_mergeSortedArray(int *arr1, const unsigned int &s1, int *arr2, const unsigned int &s2){
    int idx = s1 + s2 - 1, i = s1 - 1, j = s2 - 1;

    while(i >= 0 && j >= 0){
        if(arr1[i] >= arr2[j]) arr1[idx--] = arr1[i--];
        else arr1[idx--] = arr2[j--];
    }

    while(j >= 0){
        arr1[idx--] = arr2[j--];
    }
}

int main()
{
    int arr1[7] {1,2,3,0,0,0,0};
    int arr2[4] {2,5,6,7};

    BF_mergeSortedArrays(arr1, 7, arr2, 4);
    printIntArray(arr1, 7);
    return 0;
}