#include<bits/stdc++.h>
using namespace std;


vector<int> nsl(vector<int> nums){
    vector<int> out;
    stack<pair<int, int>> s;
    int n = nums.size();
    for(int i = 0; i < n; i++){
        if(s.empty()){
            out.push_back(-1);
        }
        else if(s.top().second < nums[i]){
            out.push_back(s.top().first);
        }
        else{
            while(s.size() > 0 && s.top().second >= nums[i]){
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

vector<int> nsr(vector<int> nums){
    vector<int> out;
    stack<pair<int, int>> s;
    int n = nums.size();
    for(int i = n-1; i >= 0; i--){
        if(s.empty()){
            out.push_back(n);
        }
        else if(s.top().second < nums[i]){
            out.push_back(s.top().first);
        }
        else{
            while(s.size() > 0 && s.top().second >= nums[i]){
                s.pop();
            }
            if(s.size() == 0){
                out.push_back(n);
            }else{
                out.push_back(s.top().first);
            }
        }
        s.push({i, nums[i]});
    }
    reverse(out.begin(), out.end());
    return out;
}


int main(){                 
    vector<int> nums = {6, 2, 5, 4, 5, 1, 6};
    vector<int> left = nsl(nums);
    vector<int> right = nsr(nums);
    int max_area = 0;
    for(int i = 0; i < nums.size(); i++){
        int area = nums[i] * (right[i] - left[i] - 1);
        max_area = max(max_area, area);
    }
    cout << max_area;
    return 0;
}


// 5 2 4 7 3 5