#include<bits/stdc++.h>
using namespace std;

pair<int, int> find_missing_and_dup(vector<int> nums){
    int n = nums.size();
    int sum = 0;
    int calcSum = 0;
    for(int i = 0; i < n; i++){
        calcSum += nums[i];
        sum += i + 1;
    }

    int eq1 = calcSum - sum;
    // cout << eq1;

    sum = 0;
    calcSum = 0;
    for(int i = 0; i < n; i++){
        calcSum += pow(nums[i], 2);
        sum += pow(i+1, 2);
    }

    int eq2 = calcSum - sum;
    eq2 = eq2 / eq1;
    // cout << eq2;
    int duplicate = (eq1 + eq2) / 2;
    int missing = (eq2 - duplicate);
    return {missing, duplicate};
    
}

int main(){
    vector<int> nums = {1, 2, 2, 4, 5};
    pair<int, int> res = find_missing_and_dup(nums);
    cout << res.first << ", " << res.second;
    return 0;
}