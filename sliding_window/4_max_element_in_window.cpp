#include<bits/stdc++.h>
using namespace std;

vector<int> max_element(vector<int> nums, int k){
    int i = 0;
    int j = 0;
    vector<int> out;
    deque<int> res;
    while(j < nums.size()){
        while(res.size() > 0 && res.back() < nums[j]){
            res.pop_back();
        }
        res.push_back(nums[j]);
        if(j-i+1 < k){
            j++;
        }else if(j-i+1 == k){
            out.push_back(res.front());
            if(nums[i] == res.front()){
                res.pop_front();
            }               
            i++;
            j++; 
        }
    }
    return out;
}

int main(){
    vector<int> nums = {12, -1, -7, 8, -15, 30, 16, 28};
    int k = 3;
    for(auto i: max_element(nums, k)){
        cout << i << ", ";
    }
    return 0;
}