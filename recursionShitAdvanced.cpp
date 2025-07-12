#include <iostream>
#include <string>
#include <vector>

int sumDigitsRec(int n)
{
    n = std::abs(n);
    if (n == 0)
        return 0;
    return (n % 10) + sumDigitsRec(n / 10);
}

int digitRootRec(int n)
{
    n = std::abs(n);
    if (n < 10)
        return n;
    return digitRootRec(sumDigitsRec(n));
}

int digitRoot(int n)
{
    n = std::abs(n);
    if (n == 0)
        return 0;
    return 1 + (n - 1) % 9; // O(1) Time Complexity
}

bool isSortedRec(const std::vector<int> &vec, int size, int idx = 0)
{
    if (idx + 1 >= size)
        return true;
    return ((vec[idx] > vec[idx + 1]) ? false : isSortedRec(vec, size, idx + 1));
}

bool isPalindromeRec(const std::string &s, int start, int end)
{
    if(start >= end) return true;
    if (s[start] != s[end]) return false;
    return isPalindromeRec(s, start + 1, end - 1);
}

int main()
{   
    // --> digital root
    // int a;
    // std::cout << "Enter the number: ";
    // std::cin >> a;                                   
    // std::cout << std::endl;
    // std::cout << "The digit root of " << a << " is " << digitRootRec(a);

    // --> sorted or not
    // std::vector<int> vec = {2, 1, 3, 4};
    // int size = vec.size();

    // std::cout << (isSortedRec(vec, size) ? "Yes" : "No") << std::endl;

    // --> palindrome
    std::string s = "radar";
    std::cout << (isPalindromeRec(s, 0, s.length()-1) ? "Yes" : "No");

    return 0;
}