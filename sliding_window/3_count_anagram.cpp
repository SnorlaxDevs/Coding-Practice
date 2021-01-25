#include<bits/stdc++.h>
using namespace std;

int count_anagram(string a, string b){
    int k = b.size();
    int n = a.size();
    unordered_map<char, int> mp;
    for(int i = 0;  i < k; i++){
        mp[b[i]]++;
    }
    int count = mp.size();
    int ans = 0;
    int i = 0;
    int j = 0;
    while(j < n){
        if (mp.count(a[j]) != 0){
            mp[a[j]]--;
            if(mp[a[j]] == 0){
                count--;
            }
        }
        if(j-i+1 < k){
            j++;
        }
        else if(j-i+1 == k){
            if(count == 0){
                ans++;
            }
            if(mp.count(a[i]) != 0){
                mp[a[i]]++;
                if(mp[a[i]] == 1){
                    count++;
                }
            }
            i++;
            j++;
        }
    }
    return ans;
}

int main(){
    string a = "forxxorfxdofr";
    string b = "for";
    cout << count_anagram(a, b);
    return 0;
}