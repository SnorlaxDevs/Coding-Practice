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

int main(){
    cout << subsetSum({10, 20, 30}, 51, 3);
    return 0;
}