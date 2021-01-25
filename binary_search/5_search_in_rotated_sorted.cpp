#include<bits/stdc++.h>
using namespace std;

int bin_search(vector<int> nums, int val, int s, int e){
    int start = s;
    int end = e;
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

int array_rotated(vector<int> nums){
    int n = nums.size();
    int start = 0;
    int end = n - 1;
    while(start <= end){
        if(nums[start] < nums[end]){
            return start;
        }
        int mid = start + (end - start)/2;
        int next = (mid + 1) % n;
        int prev = (mid - 1 + n) % n;
        if (nums[mid] <= nums[next] && nums[mid] <= nums[prev]){
            return mid;
        }else if (nums[start] <= nums[mid]){
            start = mid + 1;
        }else if (nums[mid] <= nums[end]){
            end = mid - 1;
        }
    }
    return -1; 
}

int search(vector<int>& nums, int target) {
    int min_index = array_rotated(nums);
    // cout << min_index << "**" << endl;
    if(min_index == 0){
        return bin_search(nums, target, 0, nums.size() - 1);
    }else{
        int first = bin_search(nums, target, 0, min_index - 1);
        if(first != -1){
            return first;
        }else{
            return bin_search(nums, target, min_index, nums.size() - 1);
        }
    }
}

int main(){
    vector<int> nums = {4,5,6,7,0,1,2};
    cout << search(nums, 6);
    return 0;
}