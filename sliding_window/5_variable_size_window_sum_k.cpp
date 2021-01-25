#include<bits/stdc++.h>
using namespace std;

int largest_subarray_sum(vector<int> nums, int k){
    int n = nums.size();
    int i = 0;
    int j = 0;
    int mx = INT_MIN;
    int sum = 0;
    while(j < n){
        sum += nums[j];
        if(sum < k){
            j++;
        }else if(sum == k){
            mx = max(mx, j-i+1);
            j++;
        }else if(sum > k){
            while(sum > k){
                sum -= nums[i];
                i++;
            }
            j++;
        }
    }
    return mx;
}

int main(){
    vector<int> nums = {4, 1, 1, 1, 2, 3, 5};
    cout << largest_subarray_sum(nums, 5);
    return 0;
}