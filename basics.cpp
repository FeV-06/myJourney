#include <iostream>
#include <string>
#include <math.h>
#define earthRadius 6371.01
#define conversionFactor 0.01745327

void swapTwoNumbers(int &num1, int &num2){
    num2 = num2 + num1;
    num1 = num2 - num1;                         // Swap Variables Without Temp
    num2 = num2 - num1;
}

int printASCII(char c){
    return (int)c;
}

double distanceOnEarth(double latitude1, double latitude2, double longitude1, double longitude2){
    latitude1 *= conversionFactor;
    latitude2 *= conversionFactor;
    longitude1 *= conversionFactor;
    longitude2 *= conversionFactor;

    return (earthRadius * acos((sin(latitude1) * sin(latitude2)) + (cos(latitude1) * cos(latitude2) * cos(longitude1 - longitude2))));
}

int* addTwoBinaryNumbers(long bn1, long bn2, int i = 0, int r = 0){
    static int sum[20];
    while(bn1 != 0 || bn2 != 0){
        sum[i++] = (int)((bn1 % 10 + bn2 % 10 + r) % 2);
        r = (int)((bn1 % 10 + bn2 % 10 + r) / 2);
        bn1 /= 10;
        bn2 /= 10;
    }
    if(r != 0) sum[i++] = r;
    --i;

    while(i >= 0) std::cout << sum[i--];
    return sum;
}

int main(){
    // int num1 = 2, num2 = 17;
    // swapTwoNumbers(num1, num2);
    // std::cout << num1 << " " << num2 << std::endl;


    // char c = 'C';
    // int cchange = printASCII(c);
    // std::cout << cchange << std::endl;
    // std::cout << (char)cchange << std::endl;


    // String Manipulation
    // std::string str = "Hello World!";
    // std::cout << "Displaying the character at index 4: " << str.at(4) << std::endl;
    // std::cout << "Displaying the character at index 4 using array manipulation: " << str[4] << std::endl;
    // std::cout << "Displaying the length of the string: " << str.length() << std::endl;
    // std::cout << "Displaying the substring at index 6 for 3 characters " << str.substr(6, 3) << std::endl;  
    // std::cout << "Displaying the false manipulated string using concatenation: " << str + "|end|" << std::endl;
    // std::cout << "Displaying the manipulated string after using .append: " << str.append("|end|") << std::endl;
    // std::cout << "Displaying the manipulated string after using .insert: " << str.insert(3, "|insert|") << std::endl;
    // std::cout << "Displaying the manipulated string after using .replace: " << str.replace(14, 3, "Lol") << std::endl;
    // std::cout << "Enter a sentence: ";
    // std::getline(std::cin, str);
    // std::cout << "Your Input: " << str;


    // Earth Surface Distance
    // double distance, la1, la2, lo1, lo2;
    // std::cout << "Enter latitude of coordinate 1: ";
    // std::cin >> la1;

    // std::cout << "Enter latitude of coordinate 2: ";
    // std::cin >> la2;
    // std::cout << std::endl;

    // std::cout << "Enter longitude of coordinate 1: ";
    // std::cin >> lo1;

    // std::cout << "Enter longitude of coordinate 2: ";
    // std::cin >> lo2;
    // std::cout << std::endl;

    // distance = distanceOnEarth(la1, la2, lo1, lo2);
    // std::cout << "The distance between the two points is: " << distance << std::endl;


    // Add Binary Numbers
    long bn1, bn2;
    std::cout << "Enter the first binary number: ";std::cin >> bn1;
    std::cout << "Enter the second binary number: ";std::cin >> bn2;
    int* result = addTwoBinaryNumbers(bn1, bn2);
    
    return 0;
}