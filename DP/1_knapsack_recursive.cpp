#include<bits/stdc++.h>
using namespace std;

int knapsack(vector<int> val, vector<int> wt, int C, int n){
    if(n == 0 || C == 0){
        return 0;
    }

    if(wt[n-1] <= C){
        return max(val[n-1] + knapsack(val, wt, C-wt[n-1], n-1), knapsack(val, wt, C, n-1));
    }
    else{
        return knapsack(val, wt, C, n-1);
    }
}

int main(){
    cout << knapsack({60, 100, 120}, {10, 20, 30}, 50, 3);
    return 0;
}