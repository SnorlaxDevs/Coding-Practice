#include<bits/stdc++.h>
using namespace std;

int countSum(vector<int> nums, int S, int n){
    int dp[n+1][S+1];
    for(int j = 0; j < S+1; j++){
        dp[0][j] = 0;
    }
    for(int i = 0; i < n+1; i++){
        dp[i][0] = 1;
    }
    for(int i = 1; i < n+1; i++){
        for(int j = 1; j < S+1; j++){
            if(nums[i-1] <= j){
                dp[i][j] = dp[i-1][j-nums[i-1]] + dp[i-1][j];
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][S];
}

int targetSum(vector<int> nums, int S){
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if(sum < S || long(S+sum)%2 != 0){
        return 0;
    }
    int newSum = (S + sum)/2;
    return countSum(nums, newSum, nums.size());
}

int main(){
    cout << targetSum({1, 1, 1, 1, 1}, 3) << endl;
    return 0;
}