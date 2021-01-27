#include<bits/stdc++.h>
using namespace std;

vector<int> max_sub_array_sum(vector<int> nums){
    int max_so_far = INT_MIN;
    int max_ending_here = 0;
    int start = 0;
    int end = 0;
    int s = 0;
    for(int i = 0; i < nums.size(); ++i){
        max_ending_here += nums[i];
        if(max_so_far < max_ending_here){
            max_so_far = max_ending_here;
            start = s;
            end = i;
        }
        if(max_ending_here < 0){
            max_ending_here = 0;
            s = i+1;
        }
    } 
    return {max_so_far, start, end};
}

int main(){
    for(auto i: max_sub_array_sum({-24,-1, 21, 45, -89, 61, 12, -2})){
        cout << i << ", ";
    }
    return 0;
}