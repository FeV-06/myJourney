#include <iostream>
#include <vector>

void traverseArray(const std::vector<int> &arr){
    for(int x : arr){
        std::cout << x << " ";
    }
    std::cout << std::endl;
}


int linearSearchVec(std::vector<int> &vec, int target){
    for(int i = 0; i < vec.size(); i++){
        if(target == vec[i]) return i;
    }
    return -1;
}

int binarySearchVec(std::vector<int> &vec, int target){
    int st = 0, end = vec.size() - 1, mid = st + (end - st) / 2;
    
    while(st <= end){
        mid = st + (end - st) / 2;
        if(target == vec[mid]) return mid;
        if(target > vec[mid]) st = mid + 1;
        else end = mid - 1;
    }
    return -1;
}

void takeInputVec(std::vector<int> &vec, int input = 0){
    while(true){
        std::cout << "Enter a number (-1 to show the complete vector): ";
        std::cin >> input;                        // loop for vector inputs (-1 will exit the loop)
        if(input == -1) break;
        vec.push_back(input);
    }
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
    int size, target, count = 0;
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

    takeInputVec(vec);
    traverseVector(vec);    // prints output vector to the console

    std::cout << "Enter the number you want to find: ";
    std::cin >> target;
    std::cout << std::endl << "The index of the " << target << " you want to find is: " << linearSearchVec(vec, target);
    
    return 0;
}