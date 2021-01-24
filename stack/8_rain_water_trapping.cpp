#include<bits/stdc++.h>
using namespace std;

int rain_water(vector<int> nums){
    int n = nums.size();
    int maxl[n];
    int maxr[n];
    maxl[0] = nums[0];
    for(int i = 1; i < n; i++){
        maxl[i] = max(maxl[i-1], nums[i]);
    }
    maxr[n-1] = nums[n-1];
    for(int i = n-2; i >= 0; i--){
        maxr[i] = max(maxr[i+1], i);
    }

    int water[n];
    for(int i = 0; i < n; i++){
        water[i] = min(maxr[i], maxl[i]) - nums[i];
    }

    return accumulate(water, water + n, 0);
}

int main(){
    vector<int> arr = {3, 0, 2, 0, 4};
    cout << rain_water(arr);
    return 0;
}