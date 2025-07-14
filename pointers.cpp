#include <iostream>
#include <cstdlib>
#include <ctime>

void makeZero(int *n)
{
    *n = 0;
}

void printArray(int arr[], const int size)
{
    int temp = *arr;
    for (int i = 0; i < size; i++)
    {
        // std::cout << arr[0] << " ";
        std::cout << *(arr + i) << " ";
    }

    std::cout << std::endl;
}

void reverseArray(int *arr, const int size)
{
    int *start = arr, *end = arr + size - 1;
    while (start < end)
    {
        int temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}

int sumArray(int *arr, const int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += *(arr + i);
    }
    return sum;
}

char *myStrCopy(char *dest, char *src)
{
    char *temp = dest;
    while (*src != '\0')
    {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
    return temp;
}

int *mergeSortedArrays(int *arr1, int *arr2, int size1, int size2)
{
    int *result = new int[size1 + size2];
    int i = 0, j = 0, k = 0;

    while (i < size1 && j < size2)
    {
        if (arr1[i] < arr2[j])
            result[k++] = arr1[i++];
        else
            result[k++] = arr2[j++];
    }

    while (i < size1)
        result[k++] = arr1[i++];
    while (j < size2)
        result[k++] = arr2[j++];

    return result;
}

int *smallestNumberArray(int *arr, int size)
{
    int *ans = arr;
    for(int i = 1; i < size; i++){
        if(*(arr+i) < *ans) ans = arr + i; 
    }
    return ans;
}

int main()
{

    int Arr[] = {7, 2, 3, -1, -10, 20}, sizeArr = sizeof(Arr) / sizeof(Arr[0]);
    std::cout << *(smallestNumberArray(Arr, sizeArr)) << std::endl;

    // int x = 10;
    // int* p = nullptr;
    // p = &x;

    // std::cout << "The value of x: " << x << std::endl;
    // std::cout << "The address of x: " << &x << std::endl;

    // std::cout << "The value of p: " << p << std::endl;
    // std::cout << "Value at p: " << *p << std::endl;    // Value of x

    // makeZero(p);            // p = address of x
    // std::cout << *p << std::endl;        // *p = x

    // int* d = new int(5);
    // std::cout << *d << std::endl;                // dynamic memory
    // delete d;

    // int arr1[] = {1,2,3};
    // int arr2[] {4,5,10};
    // int* y = arr1, *z = arr2;
    // const int size = sizeof(arr1) / sizeof(arr1[0]);
    // std::copy(std::begin(arr2), std::end(arr2), std::begin(arr1));
    // srand(time(0));
    // for(int i = 0; i < size; i++){
    //     // *(y+i) = rand() % 100 + 1;
    //     std::cout << *(y+size-i-1) << " ";
    // }

    
    int arr[] = {1, 2, 3, 4, 5};
    const int size = sizeof(arr) / sizeof(arr[0]);

    reverseArray(arr, size);
    for (int x : arr)
        std::cout << x << " ";
    std::cout << std::endl;
    // printArray(arr, size);

    char src[] = "FeV Rocks";
    char dest[50];

    myStrCopy(dest, src);
    std::cout << dest << std::endl;

    int a[] = {1, 2, 3, 4}, sizeA = 4;
    int b[] = {5, 6, 7, 9, 8}, sizeB = 5;
    int *merged = mergeSortedArrays(a, b, sizeA, sizeB);

    for (int i = 0; i < sizeA + sizeB; i++)
    {
        std::cout << *(merged + i) << " ";
    }
    std::cout << std::endl;
    delete[] merged;

    return 0;
}