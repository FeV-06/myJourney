#include <vector>
#include <iostream>

bool isValid(const int *arr, const unsigned int &size, const int maxAllowedPages, const int maxStudents){
    int st = 1, sum = 0;
    for(int i = 0; i < size; i++){
        if(arr[i] > maxAllowedPages) return false;
        if(sum + arr[i] <= maxAllowedPages){
            sum += arr[i];
        } else{
            sum = arr[i];
            st++;
        }
        if(st > maxStudents) return false;
    }
    return true;
}

int bookAllocation(const int *arr, const unsigned int &size, const int maxStudents){
    if (maxStudents > size) return -1;
    int low = 0, high = 0;
    for(int i = 0; i < size; i++){
        high += arr[i];
    }

    int st = 0, end = high, mid = st + (end - st) / 2, ans = -1;

    while(st <= end){
        mid = st + (end - st) / 2;

        if(isValid(arr, size, mid, maxStudents)){
            ans = mid;
            end = mid - 1;
        } else st = mid + 1;
    }
    return ans;
}

int main(){
    const unsigned int size = 4;
    const unsigned int maxStudents = 2;
    int arr[size] {2,1,3,4};

    std::cout << bookAllocation(arr, size, maxStudents);
    return 0;
}