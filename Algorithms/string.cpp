#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

void MreverseCharArray(char *chArr, const unsigned int &size){
    int st = 0, end = size - 1;

    while(st < end){
        std::swap(chArr[st], chArr[end]);
        st++;
        end--;
    }
}

void MreverseString(std::string &s){
    std::reverse(s.begin(), s.end());
}

void BF_MreverseVowels(std::string &s) {
    std::vector<char> vec = {'A', 'E', 'I', 'O', 'U', 'a', 'e', 'i', 'o', 'u'};
        
    int st = 0, end = s.length() - 1;
    std::cout << std::binary_search(vec.begin(), vec.end(), 'A') << '\n';
    while(st <= end){
        if(std::binary_search(vec.begin(), vec.end(), s[end]) && std::binary_search(vec.begin(), vec.end(), s[st])){
            std::swap(s[st++], s[end--]);
        }
        if(!(std::binary_search(vec.begin(), vec.end(), s[end]))) end--;
        if(!(std::binary_search(vec.begin(), vec.end(), s[st]))) st++;
    }
}

bool isVowel(char ch){
        if(ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U' || ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') return true;
        return false;
    }

void MreverseVowels(std::string &s) {
    int st = 0, end = s.length() - 1;

    while(st < end){
        while(!(isVowel(s[st])) && st < end) st++;
        while(!(isVowel(s[end])) && st < end) end--;
        if(st < end){
            std::swap(s[st++], s[end--]);
        }
    }
}

bool isValid(char ch){
    if((ch >= '0' && ch <= '9') || (tolower(ch) >= 'a' && tolower(ch) <= 'z')) return true;
    return false;
}

bool isPalindrome(const std::string &s){
    int st = 0, end = s.length() - 1;

    while(st < end){
        while(!isValid(s[st]) && st < end) st++;
        while(!isValid(s[end] && st < end)) end--;
        if(tolower(s[st]) != tolower(s[end])) return false;
    }
    return true;
}

void removeAllSubstringsFromString(std::string &str, const std::string &substr){
    while(str.length() > 0 && str.find(substr) < str.length()){
        str.erase(str.find(substr), substr.length());
    }
}

int main(){
    // REVERSE STRING 
    // std::string str = "FeV";
    // char chArr[] = {'h', 'e', 'l', 'l', 'o', '\0'};
    // int size = (sizeof(chArr) / sizeof(chArr[0])) - 1;
    // std::cout << size << '\n';
    // std::cout << "Before reversing: " << chArr << '\n';
    // reverseCharArray(chArr, size);
    // std::cout << "After reversing: " << chArr << '\n';


    // REVERSE VOWELS WITHIN A STRING
    // std::string s = "IceCreAm";
    // reverseVowels(s);
    // std::cout << s;


    // STRING PALINDROME
    // std::string s = "racecar";
    // std::cout << isPalindrome(s) << '\n';
    // char chArr = ',';


    // REMOVE ALL SUBSTRINGS FROM STRING
    std::string str = "abcabcabc", substr = "abc";
    removeAllSubstringsFromString(str, substr);
    std::cout << str;
    return 0;
}