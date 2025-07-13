#include <iostream>
#include <cstdlib>
#include <ctime>

void makeZero(int* n){
    *n = 0;
}

int main(){
    int x = 10;
    int* p = nullptr;
    p = &x;

    std::cout << "The value of x: " << x << std::endl;
    std::cout << "The address of x: " << &x << std::endl;

    std::cout << "The value of p: " << p << std::endl;
    std::cout << "Value at p: " << *p << std::endl;    // Value of x

    makeZero(p);            // p = address of x
    std::cout << *p << std::endl;        // *p = x

    int* d = new int(5);
    std::cout << *d << std::endl;                // dynamic memory
    delete d;
    
    int arr1[] = {1,2,3};
    int arr2[] {4,5,10};
    int* y = arr1, *z = arr2;
    const int size = sizeof(arr1) / sizeof(arr1[0]);
    std::copy(std::begin(arr2), std::end(arr2), std::begin(arr1));
    srand(time(0));
    for(int i = 0; i < size; i++){
        // *(y+i) = rand() % 100 + 1;
        std::cout << *(y+size-i-1) << " ";
    }
    
    return 0;
}