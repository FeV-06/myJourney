#include <iostream>

void printDescending(int n)
{
    if (n == 0)
        return;
    std::cout << n << " ";
    printDescending(n - 1);
}

void printAscending(int n)
{
    if (n == 0)
        return;
    printAscending(n - 1);
    std::cout << n << " ";
}

int factorial(int n)
{
    if (n == 0)
        return 1;
    return n * factorial(n - 1);
}

int fibonacci(int n)
{
    if (n <= 1)
        return n;
    std::cout << "fib(" << n << ") calls fib(" << n - 1 << ") + fib(" << n - 2 << ")" << std::endl;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int sumNaturalNumbers(int n)
{
    if (n == 0)
        return 0;
    return n + sumNaturalNumbers(n - 1);
}

float pow(int n, int p)
{
    if (p == 0)
        return 1;
    if(p > 0){
        return n * pow(n, p - 1);
    }
    return 1.0 / pow(n, -p);
}

void reverseString(const std::string s, int idx = 0)
{
    if (idx == s.length())
        return;
    reverseString(s, idx + 1);
    std::cout << s[idx];
}

void forwardString(const std::string s, int idx = 0)
{
    if (idx == s.length())
        return;
    std::cout << s[idx];
    forwardString(s, idx + 1);
}


int main()
{
    forwardString("Helo");
    std::cout << std::endl;
    reverseString("Helo");
    std::cout << std::endl;
    std::cout << pow(2, -5) << std::endl;
    
    return 0;
}