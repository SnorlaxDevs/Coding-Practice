#include<bits/stdc++.h>
using namespace std;

int find_floor(vector<int> nums, int val){
    int start = 0;
    int end = nums.size() - 1;
    int res = -1;
    while(start <= end){
        int mid = start + (end - start)/2;
        if (nums[mid] == val){
            return mid;
        }
        if (nums[mid] < val){
            res = mid;
            start = mid + 1;
        }else if(nums[mid] > val){
            end = mid - 1;
        }
    }
    return res; 
}

int main(){
    vector<int> nums = {1, 2, 3, 4,6, 7, 8, 12};
    cout << find_floor(nums, 5);
    return 0;
}