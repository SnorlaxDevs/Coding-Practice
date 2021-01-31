#include<bits/stdc++.h>
using namespace std;

int coinChange(vector<int> nums, int S, int n){
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
                dp[i][j] = dp[i][j-nums[i-1]] + dp[i-1][j];
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][S];
}

int main(){
    cout << coinChange({1, 2, 3}, 4, 3) << endl;
    return 0;
}