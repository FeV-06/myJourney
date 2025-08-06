#include <string>
#include <C:\GitRepos\myJourney\arrays.h>

class myClass
{
private:
    
public:
    void displayMessage(){
        std::cout << "Dynamic Object" << std::endl;
    }
};

int main(){
        // Dynamically Allocating Basic Types
    // int *dynamicInt = new int;
    // *dynamicInt = 20;
    // char *dynamicChar = new char;
    // *dynamicChar = 'C';
    // std::string *dynamicString = new std::string;
    // *dynamicString = "Gay Lesbian";
    // delete dynamicChar;
    // delete dynamicInt;
    // delete dynamicString;


        // Dynamically allocate an Array of Integers and Strings
    // const int size = 6;
    // int *dynamicIntArray = new int[size];
    // std::string *dynamicStringArray = new std::string[size];
    // for(int i = 0; i < size; i++){
    //     dynamicIntArray[i] = i+1;
    //     dynamicStringArray[i] = std::to_string(i + 1);
    // }
    // printIntArray(dynamicIntArray, size);
    // std::cout << std::endl;
    // printStringArray(dynamicStringArray, size);
    // delete[] dynamicIntArray;
    // delete[] dynamicStringArray;


        // Dynamically Allocate Memory for a Character and a String with User Input
    // char *dynamicChar = new char;
    // std::string *dynamicString = new std::string;
    // std::cout << "Enter a chracter: ";
    // std::cin >> *dynamicChar;
    // std::cin.ignore();
    // std::cout << "Enter a string: ";
    // std::getline(std::cin, *dynamicString);
    // std::cout << "Character: " << *dynamicChar << std::endl;
    // std::cout << "String: " << *dynamicString << std::endl;
    // delete dynamicChar;
    // delete dynamicString;


        // Dynamically Create an Object of a Class Using new
    // myClass *dynamicObject = new myClass;
    // dynamicObject -> displayMessage();
    // delete dynamicObject;


        // Dynamically Create an Array of Objects Using new
    // const int size = 5;
    // myClass *dynamicArray = new myClass[size];
    // for(int i = 0; i < size; i++){
    //     dynamicArray[i].displayMessage();
    // }
    // delete dynamicArray;


        // Dynamically Allocate Memory for a Structer and Input its Memebers
    
    return 0;
}