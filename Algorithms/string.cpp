#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

void reverseCharArray_M(char *chArr, const unsigned int &size){
    int st = 0, end = size - 1;

    while(st < end){
        std::swap(chArr[st], chArr[end]);
        st++;
        end--;
    }
}

void reverseChar_M(std::string &s){
    std::reverse(s.begin(), s.end());
}

void BF_reverseVowels_M(std::string &s) {
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

void reverseVowels_M(std::string &s) {
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

bool isPalindrome_N(const std::string &s){
    int st = 0, end = s.length() - 1;

    while(st < end){
        while(!isValid(s[st]) && st < end) st++;
        while(!isValid(s[end] && st < end)) end--;
        if(tolower(s[st]) != tolower(s[end])) return false;
    }
    return true;
}

void removeAllSubstrings(std::string &str, const std::string &substr){
    while(str.length() > 0 && str.find(substr) < str.length()){
        str.erase(str.find(substr), substr.length());
    }
}

bool isFreqSame(const int *freq, const int *windowFreq){
    bool check = true;
    for(int i = 0; i < 26; i++){
        if(freq[i] != windowFreq[i]) check = false;
    }
    return check;
}

bool checkInclusion_N(std::string &s1, std::string &s2){
    int freq[26] = {0};
    for(int i = 0; i < s1.length(); i++) freq[s1[i] - 'a']++;

    for(int i = 0; i < s2.length(); i++){
        int idx = i, windowIdx = 0;
        int windowFreq[26] = {0};
        
        while(windowIdx < s1.length() && idx < s2.length()){
            windowFreq[s2[idx] - 'a']++;
            windowIdx++; idx++;
        }

        if(isFreqSame(freq, windowFreq)) return true;
    }
    return false;
}

std::string reverseWords_N(std::string s){
    reverseChar_M(s);
    std::string ans = "";
    for(int i = 0; i < s.length(); i++){
        std::string word = "";
        while(i < s.length() && s[i] != ' '){
            word += s[i]; i++;
        }
        reverseChar_M(word);
        if(word.length() > 0) ans = " " + word;
    }
    return ans.substr(1);
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
    // std::string str = "abcabcabc", substr = "abc";
    // removeAllSubstringsFromString(str, substr);
    // std::cout << str;


    // Permutation In String
    // std::string s1 = "ba";
    // std::string s2 = "eidboaoo";
    // std::cout << checkInclusion_N(s1, s2);
    return 0;
}