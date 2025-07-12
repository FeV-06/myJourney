#include <iostream>


void printRightTriangle(const int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            std::cout << "*";
        }
        std::cout << std::endl;
    }
}

void printNumberTriangle(const int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            std::cout << j;
        }
        std::cout << std::endl;
    }
}

void printInvertedRightTriangle(const int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= n - i; j++)
        {
            std::cout << "*";
        }
        std::cout << std::endl;
    }
}

void printMirrorRightTriangle(const int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n - i; j++)
        {
            std::cout << " ";
        }
        for (int j = 1; j <= i; j++)
        {
            std::cout << "*";
        }
        std::cout << std::endl;
    }
}

void printEquilateralTriangle(const int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n - i; j++)
        {
            std::cout << " ";
        }
        for (int j = 1; j <= i; j++)
        {
            std::cout << "*";
        }
        if (i > 1)
        {
            for (int j = 2; j <= i; j++)
            {
                std::cout << "*";
            }
        }
        std::cout << std::endl;
    }
}

void printInvertedEquilateralTriangle(const int n)
{
    int temp = n;
    int it = 0;
    for (int i = 1; i <= n; i++)
    {
        if (i > 1)
        {
            for (int j = 2; j <= i; j++)
            {
                std::cout << " ";
            }
        }
        for (int j = 1; j <= 2 * n - i - it; j++)
        {
            std::cout << "*";
        }
        std::cout << std::endl;
        it++;
    }
}

void printFlloydTriangle(const int n)
{
    int count = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            std::cout << count << " ";
            count++;
        }
        std::cout << std::endl;
    }
}

int main()
{
    int x = 0;
    std::cout << "Enter the number of rows: " << std::endl;
    std::cin >> x;

    std::cout << std::endl
              << "Number Triangle: " << std::endl;
    printNumberTriangle(x);

    std::cout << std::endl
              << "Right Triangle: " << std::endl;
    printRightTriangle(x);

    std::cout << std::endl
              << "Inverted Right Triangle: " << std::endl;
    printInvertedRightTriangle(x);

    std::cout << std::endl
              << "Mirror Right Triangle: " << std::endl;
    printMirrorRightTriangle(x);

    std::cout << std::endl
              << "Equilateral Triangle: " << std::endl;
    printEquilateralTriangle(x);

    std::cout << std::endl
              << "Inverted Equilateral Triangle: " << std::endl;
    printInvertedEquilateralTriangle(x);

    std::cout << std::endl
              << "Flloyd's Triangle: " << std::endl;
    printFlloydTriangle(x);

    return 0;
}