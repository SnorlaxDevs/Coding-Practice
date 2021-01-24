#include<bits/stdc++.h>
using namespace std;

vector<int> ngl(vector<int> nums){
    vector<int> out;
    stack<pair<int, int>> s;
    int n = nums.size();
    for(int i = 0; i < n; i++){
        if(s.empty()){
            out.push_back(-1);
        }
        else if(s.top().second > nums[i]){
            out.push_back(s.top().first);
        }
        else{
            while(s.size() > 0 && s.top().second <= nums[i]){
                s.pop();
            }
            if(s.size() == 0){
                out.push_back(-1);
            }else{
                out.push_back(s.top().first);
            }
        }
        s.push({i, nums[i]});
    }
    return out;
}

vector<int> stock_span(vector<int> nums){
    vector<int> ngl_ = ngl(nums); 
    for(int i = 0; i < nums.size(); i++){
        ngl_[i] = i - ngl_[i];
    }
    return ngl_;
}

int main(){
    vector<int> nums = {100, 80, 60, 70, 60, 75, 85};
    vector<int> out = stock_span(nums);
    for(auto i: out){
        cout << i << " ";
    }
}