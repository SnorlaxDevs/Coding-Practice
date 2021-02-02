#include<bits/stdc++.h>
using namespace std;

string LCS(string a, string b){
    int m = a.size();
    int n = b.size();
    int dp[m+1][n+1];
    for(int i = 0; i < m+1; i++){
        for(int j = 0; j < n+1; j++){
            if(i==0 || j==0){
                dp[i][j] = 0;
            }
        }
    }
    for(int i = 1; i < m+1; i++){
        for(int j = 1; j < n+1; j++){
            if(a[i-1] == b[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    string res;
    int i = m;
    int j = n;
    while(j > 0 && i > 0){
        if(a[i-1] == b[j-1]){
            res.push_back(a[i-1]);
            --i;
            --j;
        }else{
            if(dp[i-1][j] > dp[i][j-1]){
                --i;
            }else{
                --j;
            }
        }
    }
    reverse(res.begin(), res.end());
    return res;
}

int main(){
    cout << LCS("abcdefg", "acdfxg") << endl;
    return 0;
}