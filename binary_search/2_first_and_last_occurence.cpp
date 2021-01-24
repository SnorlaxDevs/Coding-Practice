#include<bits/stdc++.h>
using namespace std;

int first_occurence(vector<int> nums, int val){
    int start = 0;
    int end = nums.size() - 1;
    int res = -1;
    while(start <= end){
        int mid = start + (end - start)/2;
        if (nums[mid] == val){
            res = mid;
            end = mid - 1;
        }else if (nums[mid] < val){
            start = mid + 1;
        }else{
            end = mid - 1;
        }
    }
    return res; 
}

int last_occurence(vector<int> nums, int val){
    int start = 0;
    int end = nums.size() - 1;
    int res = -1;
    while(start <= end){
        int mid = start + (end - start)/2;
        if (nums[mid] == val){
            res = mid;
            start = mid + 1;
        }else if (nums[mid] < val){
            start = mid + 1;
        }else{
            end = mid - 1;
        }
    }
    return res; 
}

int main(){
    vector<int> nums = {1, 2, 3, 3, 3, 3, 3, 4, 6, 7, 7, 8, 12};
    cout << first_occurence(nums, 3) << " " << last_occurence(nums, 3);
    return 0;
}