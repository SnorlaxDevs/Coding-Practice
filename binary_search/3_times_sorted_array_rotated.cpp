#include<bits/stdc++.h>
using namespace std;

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
        // cout << next << " ** " << prev << endl; 
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

int main(){
    vector<int> nums = {4,5,6,7,0,1,2};
    cout << array_rotated(nums);
    return 0;
}