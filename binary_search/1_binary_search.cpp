#include<bits/stdc++.h>
using namespace std;

int bin_search(vector<int> nums, int val){
    int start = 0;
    int end = nums.size() - 1;
    while(start <= end){
        int mid = start + (end - start)/2;
        if (nums[mid] == val){
            return mid;
        }else if (nums[mid] < val){
            start = mid + 1;
        }else{
            end = mid - 1;
        }
    }
    return -1; 
}

int main(){
    vector<int> nums = {1, 2, 3, 4,6, 7, 8, 12};
    cout << bin_search(nums, 3);
    return 0;
}