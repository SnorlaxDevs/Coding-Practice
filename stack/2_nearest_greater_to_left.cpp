#include<bits/stdc++.h>

using namespace std;

vector<int> ngl(vector<int> nums){
    vector<int> out;
    stack<int> s;
    int n = nums.size();
    for(int i = 0; i < n; i++){
        if(s.empty()){
            out.push_back(-1);
        }
        else if(s.top() > nums[i]){
            out.push_back(s.top());
        }
        else{
            while(s.size() > 0 && s.top() <= nums[i]){
                s.pop();
            }
            if(s.size() == 0){
                out.push_back(-1);
            }else{
                out.push_back(s.top());
            }
        }
        s.push(nums[i]);
    }
    // reverse(out.begin(), out.end());
    return out;
}

int main(){
    vector<int> nums = {1,2,4,3,5,2,8};
    vector<int> out = ngl(nums);
    for(auto i: out){
        cout << i << ", ";
    }
    return 0;
}