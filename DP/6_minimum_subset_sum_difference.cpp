#include<bits/stdc++.h>
using namespace std;

vector<bool> subsetSum(vector<int> nums, int S, int n){
    vector<bool> possibleSums;
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
    for(int i = 0; i <= S; i++){
        possibleSums.push_back(dp[n][i]);
    }
    return possibleSums;
}

int minSubsetDiff(vector<int> nums, int n){
    int sum = accumulate(nums.begin(), nums.end(), 0);
    vector<bool> possibleSum = subsetSum(nums, sum, nums.size());
    int mn = INT_MAX;
    for(int i = 0; i < possibleSum.size()/2; i++){
        if(possibleSum[i] == true){
            mn = min(mn, sum - 2*i);
        }
    }
    return mn;
}

int main(){
    cout << minSubsetDiff({1, 6, 15, 5}, 4);
    return 0;
}