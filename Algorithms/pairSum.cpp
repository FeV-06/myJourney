#include "array.cpp"
#include <iostream>
#include <vector>

void BF_pairSum(const int *arr, const unsigned int &size, const int &target){ // O(n^2), also not limited to just one pair in an array
    for(int i = 0; i < size; i++){
        for(int j = i + 1; j < size; j++){
            if(arr[i] + arr[j] == target) std::cout << "The indices of the pairs that matches the target: (" << i << ", " << j << ")\n"; 
        }
    }
}

std::vector<int> BF_pairSum(const std::vector<int> &vec, const int &target){ // O(n^2), but only limited to just one pair in a vector
    std::vector<int> ans;       // if more than one pair is present, stores the first pair encountered
    
    for(int i = 0; i < vec.size(); i++){
        for(int j = i+1; j < vec.size(); j++){
            if(vec[i] + vec[j] == target){
                ans.push_back(i);
                ans.push_back(j);
                return ans;
            }
        }
    }

    return ans;
}

std::vector<int> OPT_pairSum(const std::vector<int> &vec, const unsigned int &target){ // O(n), but only limited to just one pair in a vector
    int st = 0, end = vec.size()-1, pS = 0; // if more than one pair is present, stores the first pair encountered
    std::vector<int> ans;
    while(st < end){
        pS = vec[st] + vec[end]; 
        if(pS == target){
            ans.push_back(st);
            ans.push_back(end);
            return ans;
        }
        if(pS > target) end--;
        if(pS < target) st++;
    }
    return ans;
}

int main(){
    std::vector<int> vec {1,2,3,4,5};
    const int target = 5;
    std::vector<int> ans = OPT_pairSum(vec, target);
    std::cout << "Vector Pair Sum:\n";
    for(int x : ans) std::cout << x << " ";
    std::cout << '\n';

    const unsigned int size = 5;
    int arr[size] {1,2,3,4,5};
    std::cout << "\nArray Pair Sum:\n";
    BF_pairSum(arr, size, target);
    
    return 0;
}