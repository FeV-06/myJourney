#include <iostream>
#include <string>



int main(){
    char chArr[] = {'h', 'e', 'l', 'l', 'o', '\0'};
    int size = sizeof(chArr) / sizeof(chArr[0]);

    std::cout << "The size is: " << size;
    return 0;
}