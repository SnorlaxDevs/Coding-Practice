#include<bits/stdc++.h>
using namespace std;

void swap_sort(vector<int>& nums){
    for(int i = 0; i < nums.size(); i++){
        if(nums[i] != nums[nums[i] - 1]){
            // int temp = nums[i];
            // nums[i] = nums[nums[i] - 1];
            // nums[nums[i] - 1] = temp;
            // cout << nums[i] << ", " << nums[nums[i] - 1] << endl ;
            swap(nums[i], nums[nums[i] - 1]);
        }
    }
}

int main(){
    vector<int> nums = {3, 5, 1, 2, 2};
    swap_sort(nums);
    for(auto i: nums){
        cout << i << ", ";
    }
    return 0;
}