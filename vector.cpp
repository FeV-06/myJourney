#include <iostream>
#include <vector>

void traverseArray(const std::vector<int> &arr){
    for(int x : arr){
        std::cout << x << " ";
    }
    std::cout << std::endl;
}

void traverseVector(const std::vector<int> &vec){
    for(int x : vec){
        std::cout << x << " ";
    }
    std::cout << std::endl;
}

int main()
{   
    // initializing important datatypes
    int size, input, count = 0;
    std::vector<int> vec = {};

    // taking input for array
    std::cout << "Enter a number to determine the size of an array: ";
    std::cin >> size;
    if(size <= 0) {
        std::cout << "Not Possible!";             // good for invalid size case
        return 0;
    }
    std::vector<int> arr(size);         // setting up the final array of fixed size
    std::cout << std::endl;

    while (count != size)
    {
        std::cout << "Enter a number: ";
        std::cin >> arr[count];                            // loop for array inputs
        count++;
    }
    traverseArray(arr);   // prints output array to the console
    std::cout << std::endl;

    while(true){
        std::cout << "Enter a number (-1 to show the complete vector): ";
        std::cin >> input;                        // loop for vector inputs (-1 will exit the loop)
        if(input == -1) break;
        vec.push_back(input);
    }
    traverseVector(vec);    // prints output vector to the console
    return 0;
}