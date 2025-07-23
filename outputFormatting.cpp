#include<iostream>
#include <iomanip>
int main(){
    double pi = 3.14159265;
    std::cout << std::fixed << std::setprecision(4);
    std::cout << "The value of pi upto 4 decimal places with width of 8: |" << std::setw(8) << pi << "|" << std::endl;
    std::cout << "The value of pi upto 4 decimal places with width of 10: |" << std::setw(10) << pi << "|" << std::endl;

    std::cout << std::setfill('-');
    std::cout << "The value of pi upto 4 decimal places with width of 8: |" << std::setw(8) << pi << "|" << std::endl;
    std::cout << "The value of pi upto 4 decimal places with width of 10: |" << std::setw(10) << pi << "|" << std::endl;

    std::cout << std::scientific;
    std::cout << "The value of pi with a scientific format is: " << pi << std::endl;

    bool done = false;
    std::cout << "Status in number: " << done << std::endl;
    std::cout << std::boolalpha;

    std::cout << "Status in words: " << done << std::endl;
    return 0;
}