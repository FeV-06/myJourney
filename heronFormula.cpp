#include <iostream>
#include <math.h>

class heronFormula
{
private:
    float s1, s2, s3;
public:
    heronFormula(float side1, float side2, float side3) : s1(side1), s2(side2), s3(side3) {}

    float hF() const{
        float s = (s1 + s2 + s3) / 2;
        return sqrt(s * (s-s1) * (s-s2) * (s-s3));
    }
};




int main(){
    float s1, s2, s3;

    std::cout << "Input the length of side 1: ";
    std::cin >> s1;
    std::cout << std::endl;

    std::cout << "Input the length of side 2: ";
    std::cin >> s2;
    std::cout << std::endl;

    std::cout << "Input the length of side 3: ";
    std::cin >> s3;
    heronFormula traingle(s1,s2,s3);
    std::cout << std::endl;
    
    std::cout << "The area is: " << traingle.hF();

    return 0;
}