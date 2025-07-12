#include <iostream>

class number
{
private:
    int a;

public:
    number(int n) : a(n) {}

    int getValue() const{
        return a;
    }

    bool isOdd() const
    {
        int temp = a;
        temp = std::abs(temp);
        return temp > 0 && (temp & 1) == 1;
    }

    bool isPowerOfTwo() const{
        return a > 0 && (a & (a-1)) == 0;
    }

    int clsRightmostBit() const{
        return a & (a-1);
    }

    int countOnes() const{
        unsigned int temp = static_cast<int>(a);
        int count = 0;
        while(temp > 0){
            count += (temp & 1);
            temp >>= 1;
        }
        return count;
    }

    bool isIthBit(int i) const{
        return (a & (1 << i)) != 0;
    }

    int turnOnTheIthBit(int i) const{
        return a | (1 << i);
    }

    int turnOffTheIthBit(int i) const{
        return a & ~(1 << i);
    }

    int toggleIthBit(int i) const{
        return a ^ (1 << i);
    }
};

int main()
{
    int a = 8, b = 3, tempA, tempB, iA = 2, iB = 1;
    number A(a);
    number B(b);

    if(B.isOdd()) std::cout << B.getValue() << " is odd." << std::endl;
    else std::cout << B.getValue() << " is even." << std::endl;

    if(B.isPowerOfTwo()) std::cout << B.getValue() << " is a power of two." << std::endl;
    else std::cout << B.getValue() << " is not a power of two." << std::endl;

    tempB = B.clsRightmostBit();
    std::cout << "The number before clearing the right most bit: " << B.getValue() << "\nAnd after clearing the right most bit: " << tempB << std::endl;

    std::cout << "The number of ONES in " << B.getValue() << " is " << B.countOnes() << std::endl;

    if(A.isIthBit(3)) std::cout << "Yes, that position has a bit." << std::endl;
    else std::cout << "That position doesn't have a bit." << std::endl;

    tempA = A.turnOnTheIthBit(iA);
    std::cout << "The number before turning on the bit: " << A.getValue() << "\nThe number after turning on the bit at postion " << iA << ": " << tempA << std::endl;
    // std::cout << B.getValue() << std::endl;

    tempB = B.turnOffTheIthBit(iB);
    std::cout << "The number before turning off the bit: " << B.getValue() << "\nThe number after turning off the bit at postion " << iB << ": " << tempB << std::endl;

    tempA = A.toggleIthBit(iA);
    std::cout << "The number before toggling the bit: " << A.getValue() << "\nThe number after toggling the bit at postion " << iA << ": " << tempA << std::endl;
    return 0;
}