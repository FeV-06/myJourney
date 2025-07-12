#include <iostream>

class Triangle
{
private:
    int n;
    char fillChar;

public:
    Triangle(int a, char c) : n(a), fillChar(c) {}

    void printEquilateralTriangle(int offset) const
    {
        std::cout << std::endl
                  << "Equilateral Triangle: " << std::endl;
        for (int i = 1; i <= n; i++)
        {
            for (int o = 1; o <= offset; o++)
            {
                std::cout << " ";
            }
            for (int j = 1; j <= n - i; j++)
            {
                std::cout << " ";
            }
            for (int j = 1; j <= i; j++)
            {
                std::cout << fillChar;
            }
            if (i > 1)
            {
                for (int j = 2; j <= i; j++)
                {
                    std::cout << fillChar;
                }
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
    void printRightTriangle(int offset) const
    {
        std::cout << std::endl
                  << "Right Triangle: " << std::endl;
        for (int i = 1; i <= n; i++)
        {
            for (int o = 1; o <= offset; o++)
            {
                std::cout << " ";
            }
            for (int j = 1; j <= i; j++)
            {
                std::cout << fillChar;
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
    void printNumberTriangle(int offset) const
    {
        std::cout << std::endl
                  << "Number Triangle: " << std::endl;
        for (int i = 1; i <= n; i++)
        {
            for (int o = 1; o <= offset; o++)
            {
                std::cout << " ";
            }
            for (int j = 1; j <= i; j++)
            {
                std::cout << j << " ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }

    void printInvertedRightTriangle(int offset) const
    {
        std::cout << std::endl
                  << "Inverted Right Triangle: " << std::endl;
        for (int i = 1; i <= n; i++)
        {
            for (int o = 1; o <= offset; o++)
            {
                std::cout << " ";
            }
            for (int j = 0; j <= n - i; j++)
            {
                std::cout << fillChar;
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }

    void printMirrorRightTriangle(int offset) const
    {
        std::cout << std::endl
                  << "Mirror Right Triangle: " << std::endl;
        for (int i = 1; i <= n; i++)
        {
            for (int o = 1; o <= offset; o++)
            {
                std::cout << " ";
            }
            for (int j = 1; j <= n - i; j++)
            {
                std::cout << " ";
            }
            for (int j = 1; j <= i; j++)
            {
                std::cout << fillChar;
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }

    void printInvertedEquilateralTriangle(int offset) const
    {
        int temp = n;
        int it = 0;
        std::cout << std::endl
                  << "Inverted Equilateral Triangle: " << std::endl;
        for (int i = 1; i <= n; i++)
        {
            for (int o = 1; o <= offset; o++)
            {
                std::cout << " ";
            }
            if (i > 1)
            {
                for (int j = 2; j <= i; j++)
                {
                    std::cout << " ";
                }
            }
            for (int j = 1; j <= 2 * n - i - it; j++)
            {
                std::cout << fillChar;
            }
            std::cout << std::endl;
            it++;
        }
        std::cout << std::endl;
    }

    void printFlloydTriangle(int offset) const
    {
        int count = 1;
        std::cout << std::endl
                  << "Flloyd's Triangle: " << std::endl;
        for (int i = 1; i <= n; i++)
        {
            for (int o = 1; o <= offset; o++)
            {
                std::cout << " ";
            }
            for (int j = 1; j <= i; j++)
            {
                std::cout << count << " ";
                count++;
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
};

int main()
{
    int n, offset;
    char c;
    std::cout << "Enter the number of rows: ";
    std::cin >> n;

    std::cout << "Enter the offset: ";
    std::cin >> offset;

    std::cout << "Enter the character: ";
    std::cin >> c;

    Triangle t(n, c);
    t.printEquilateralTriangle(offset);
    t.printRightTriangle(offset);
    t.printFlloydTriangle(offset);
    t.printInvertedEquilateralTriangle(offset);
    t.printInvertedRightTriangle(offset);
    t.printMirrorRightTriangle(offset);
    t.printNumberTriangle(offset);
    std::cout << -1234 / 10000;
    return 0;
}