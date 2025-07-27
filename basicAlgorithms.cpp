#include <iostream>
#include <math.h>
#include <algorithm>

int tripleSumForSameValues(const int &a,const int &b){
    if(a == b) return 3 * (a + b);
    return a + b;
}

int absoluteDifferenceWith51(const int &num){
    if(num > 51) return 3 * std::abs(51 - num);
    return std::abs(51 - num);
}

bool check30sum30(const int &num1, const int &num2){
    if(num1 == 30 || num2 == 30 || num1 + num2 == 30) return true;
    return false;
}

bool within10of100or200(const int &num){
    if((num >= 90 && num <= 110) || (num >= 190 && num <= 210)) return true;
    return false;
}

std::string addIfToString(const std::string &str){
    if(str.length() > 2 && str.substr(0, 2) == "if") return str;
    return "if " + str;
}

std::string removeCharacterFromString(std::string &str, const int &first, const int &last){
    if(first >= str.length()) return "Out of Bounds!";
    return str.erase(first, last);
}   

std::string swapFirstLastCharacters(std::string &str){
    if(str.length() == 0) return "B!tch";
    char temp = str[0];
    str[0] = str[str.length() - 1];
    str[str.length() - 1] = temp;
    return str;
}

std::string RmultiplyStrings(std::string str, int num, int limit = 0, int count = 1){
    // if(str.length() < 2) return str;
    if(limit == 0) limit = str.length();
    str = str.substr(0, limit);
    if(count == num) return str;
    count++;
    return str + " " + RmultiplyStrings(str, num, limit, count);
}

bool multipleOf3and7(const int &num){
    if(num % 3 == 0 || num % 7 == 0) return true;
    return false;
}

std::string addFirst3CharactersToFB(std::string &str){
    std::string substr = str.substr(0, 3);
    return substr + str + substr;
}

bool checkStringStartsWith(std::string &str, std::string check = "C#"){
    if(str.substr(0, check.length()) == check) return true;
    return false;
}

bool tempLessThan0orGreaterThan100(const int &num1, const int &num2){
    if((num1 < 0 && num2 > 100) || (num2 < 0 && num1 > 100)) return true;
    return false;
}

int main(){
        // Triple Sum for Same Values
    // int num1 = 6, num2 = 6;
    // std::cout << tripleSumForSameValues(num1, num2);


        // Absolute Difference with 51
    // int num = 53;
    // std::cout << absoluteDifferenceWith51(num);


        // Check 30 or Sum 30
    // int num1 = 25, num2 = 20;
    // std::cout << check30sum30(num1, num2);


        // Within 10 of 100 or 200
    // int num = 200;
    // std::cout << within10of100or200(num);


        // Add "if" to String
    // std::string str = "gay else lesbian";
    // std::cout << addIfToString(str) << std::endl;


        // Remove Character from String
    // std::string str = "Wow, look at that!";               // Also changes the original string
    // std::cout << removeCharacterFromString(str, 20, 2);

    
        // Swap First and Last Characters in a String
    // std::string str = "abcd";
    // std::cout << swapFirstLastCharacters(str) << std::endl;


        // Copies of First n Characters
    // std::string str = "Hello";
    // std::cout << RmultiplyStrings(str, 3);


        // Multiple of 3 & 7
    // int num = 1;
    // std::cout << multipleOf3and7(num);


        // Add First 3 Character to Front and Back
    // std::string str = "GayLesbian";
    // std::cout << addFirst3CharactersToFB(str);


        // Check If String Starts with 'C#'
    // std::string str = "Hello, and please die!", check = "Hello";
    // std::cout << checkStringStartsWith(str, check);


        // Temperature Less Than 0 or Greater Than 100
    // int num1 = 2, num2 = 120;
    // std::cout << tempLessThan0orGreaterThan100(num1, num2);


        // Check If Integers are in Range 100
    return 0;
}