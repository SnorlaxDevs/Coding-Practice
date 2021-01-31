#include<bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> price, vector<int> rodLen, int n){
    int dp[n+1][n+1];
    for(int i = 0; i < n+1; i++){
        for(int j = 0; j < n+1; j++){
            if(i == 0 || j == 0){
                dp[i][j] = 0;
            }
        }
    }
    for(int i = 1; i < n+1; i++){
        for(int j = 1; j < n+1; j++){
            if(rodLen[i-1] <= j){
                dp[i][j] = max(price[i-1] + dp[i][j - rodLen[i-1]], dp[i-1][j]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][n];
}

int main(){
    cout << maxProfit({1, 5, 8, 9, 10, 17, 17, 20}, {1, 2, 3, 4, 5, 6, 7, 8}, 8) << endl; 
    return 0;
}