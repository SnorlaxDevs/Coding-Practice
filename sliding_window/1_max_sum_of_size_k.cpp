#include<bits/stdc++.h>
using namespace std;

int max_sum(vector<int> nums, int k){
    int i = 0;
    int j = 0;
    int sum = 0;
    int mx = INT_MIN;
    while(j < nums.size()){
        sum += nums[j];
        if(j-i+1 < k){
            j++;
        }else if(j-i+1 == k){
            mx = max(mx, sum);
            sum -= nums[i];
            i++;
            j++;
        }
    }
    return mx;
}

int main(){
    vector<int> nums = {12, 42, 1, 23, 4, 34, 11, 7, 0};
    int k = 3;
    cout << max_sum(nums, k);
    return 0;
}