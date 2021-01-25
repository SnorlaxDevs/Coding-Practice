#include<bits/stdc++.h>
using namespace std;

vector<int> negative_elements(vector<int> nums, int k){
    int i = 0;
    int j = 0;
    vector<int> out;
    deque<int> res;
    while(j < nums.size()){
        if(nums[j] < 0){
            res.push_back(nums[j]);
        }
        if(j-i+1 < k){
            j++;
        }else if(j-i+1 == k){
            if(res.empty()){
                out.push_back(0);
            }else{
                out.push_back(res.at(0));
                if(nums[i] == res[0]){
                    res.pop_front();
                }      
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
    for(auto i: negative_elements(nums, k)){
        cout << i << ", ";
    }
    return 0;
}