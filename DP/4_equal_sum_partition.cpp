#include<bits/stdc++.h>
using namespace std;

bool subsetSum(vector<int> nums, int S, int n){
    bool dp[n+1][S+1];
    for(int j = 0; j <= S; j++){
        dp[0][j] = false;
    }
    
    for(int i = 0; i <= n; i++){
        dp[i][0] = true;
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= S; j++){
            if(nums[i-1] <= j){
                dp[i][j] = dp[i-1][j-nums[i-1]] || dp[i-1][j];
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][S];
}

bool equalSum(vector<int> nums, int n){
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if(sum & 1){
        return false;   
    }
    return subsetSum(nums, sum/2, n);
}
int main(){
    vector<int> nums = {1, 5, 11, 5};
    cout << equalSum(nums, nums.size());
    return 0;
}