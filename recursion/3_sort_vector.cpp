#include<bits/stdc++.h>
using namespace std;

void insert(vector<int>& nums, int val){
    if(nums.size() == 0 || nums[nums.size()-1] <= val){
        nums.push_back(val);
        return;
    }
    int temp = nums[nums.size() - 1];
    nums.pop_back();
    insert(nums, val);
    nums.push_back(temp);
}

void recursive_sort(vector<int>& nums){
    if(nums.size() == 1){
        return;
    }
    int val = nums[nums.size() - 1];
    nums.pop_back();
    recursive_sort(nums);
    insert(nums, val);    
}

int main(){
    vector<int> nums = {2, 3, 1, 0, 5, 9};
    recursive_sort(nums);
    for(auto i: nums){
        cout << i << ", ";
    }
    return 0;
}