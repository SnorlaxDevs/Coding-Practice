#include<bits/stdc++.h>
using namespace std;

int longest_sub(string s, int k){
    int n = s.size();
    int i = 0;
    int j = 0;
    int mx = INT_MIN;
    unordered_map<char, int> mp;
    while(j < n){
        mp[s[j]]++;
        if(mp.size() < k){
            j++;
        }
        else if(mp.size() == k){
            mx = max(mx, j-i+1);
            j++;
        }
        else if(mp.size() > k){
            while(mp.size() > k){
                mp[s[i]]--;
                if(mp[s[i]] == 0){
                    mp.erase(s[i]);
                }
                i++;
            }
            j++;
        } 
    }
    return mx;
}

int main(){
    cout << longest_sub("aabacbebebe", 2) << endl;
    return 0;
}