#include <iostream>
#include <vector>
#include <algorithm>

bool comparator(std::pair<int, int> p1, std::pair<int, int> p2) // prioritise the second value of a pair comparison first
{   // if found equal second values in the pair, then sorting based on the first value of the pairs
    if(p1.second < p2.second) return true;
    if(p1.second > p2.second)return false;

    if(p1.first < p2.first) return true;
    if(p1.first > p2.first) return false;
}

int main()
{
    std::vector<std::pair<int,int>> vec = {{1,2}, {3,4}, {2,3}, {7,2}};
    std::sort(vec.begin(), vec.end(), comparator);

    for(auto p : vec){
        std::cout << p.first << " " << p.second << '\n';
    }
    return 0;
}