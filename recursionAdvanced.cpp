#include <iostream>
#include <math.h>

class numbers
{
private:
    int n;
    int div = 10;

    int countDigitsRecHelper(int a) const
    {
        if (a < 10)
            return 1;
        return 1 + countDigitsRecHelper(a / 10);
    }

    int sumDigitsRecHelper(int a) const
    {
        if (a == 0)
            return 0;
        return (a % 10) + sumDigitsRecHelper(a / 10);
    }

public:
    numbers(int a) : n(std::abs(a)) {}

    // int getValue() const{
    //     return n;
    // }

    int getValue() const { return n; }

    int countDigits()
    {
        int temp = n;
        int count = 0;
        while (true)
        {
            if (temp == 0)
                return count;
            temp /= div;
            count++;
        }
    }

    int sumDigits()
    {
        int mod, temp = n, ans = 0;
        while (temp != 0)
        {
            mod = temp % div;
            ans += mod;
            temp /= 10;
        }
        return ans;
    }

    int countDigitsRec() const
    {
        return countDigitsRecHelper(n);
    }

    int sumDigitsRec() const
    {
        return sumDigitsRecHelper(n);
    }
};

class linePattern
{
private:
    int col;
    char fillChar;

    void printStarsRecHelper(int x) const
    {
        if (x == 0)
            return;
        printStarsRecHelper(x - 1);
        std::cout << fillChar << " ";
    }

public:
    linePattern(int b, char c) : col(b), fillChar(c) {}

    void printStarsRec() const
    {
        printStarsRecHelper(col);
    }
};

class trianglePattern
{
private:
    int row;
    char fillChar;

    void printStarsRecHelper(int x) const
    {
        if (x == 0)
            return;
        printStarsRecHelper(x - 1);
        std::cout << fillChar << " ";
    }

    void printTriangleRecHelper(int y) const
    {
        if (y == 0)
            return;
        printTriangleRecHelper(y - 1);
        printStarsRecHelper(y);
        std::cout << std::endl;
    }

public:
    trianglePattern(int a, char c) : row(a), fillChar(c) {}

    void printTriangleRec() const
    {
        printTriangleRecHelper(row);
    }
};

class strings
{
private:
    std::string s;

public:
    strings(std::string S) : s(S) {}

    void powerSetStrings(std::string current = "", int i = 0) const
    {
        
        if (i == s.length())
        {
            std::cout << current << std::endl;
            return;
        }
        
        powerSetStrings(current, i + 1);
        powerSetStrings(current + s[i], i + 1);

    }
};

int main()
{
    int row, col, choice;
    char c;

    // std::cout << "Choose among the following:\n1)Print Character only\n2)Print Triangle Only\nEnter a number(1 or 2): ";
    // std::cin >> choice;
    // std::cout << std::endl;

    // if (choice == 1)
    // {
    //     std::cout << "Enter the number of Characters you want: ";
    //     std::cin >> col;
    
    //     std::cout << std::endl
    //               << "Enter the Character: ";
    //     std::cin >> c;

    //     linePattern t(col, c);
    //     t.printStarsRec();
    // }
    // else if (choice == 2)
    // {
    //     std::cout << "Enter the number of rows you want: ";
    //     std::cin >> row;

    //     std::cout << std::endl
    //               << "Enter the Character: ";
    //     std::cin >> c;

    //     trianglePattern t(row, c);
    //     t.printTriangleRec();
    // }
    // else
    // {
    //     std::cout << "Wrong Input!" << std::endl;
    // }

    // numbers t(n);
    // std::cout << t.countDigits() << std::endl;
    // std::cout << t.sumDigits() << std::endl << t.countDigitsRec();'

    std::string s = "abc";
    strings S(s);

    S.powerSetStrings();
    return 0;
}