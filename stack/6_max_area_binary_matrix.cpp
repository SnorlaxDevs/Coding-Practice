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


int MAH(vector<int> nums){
    vector<int> left = nsl(nums);
    vector<int> right = nsr(nums);
    int max_area = 0;
    for(int i = 0; i < nums.size(); i++){
        int area = nums[i] * (right[i] - left[i] - 1);
        max_area = max(max_area, area);
    }
    return max_area;
}
int main(){
    int arr[4][4] = {
        {0, 1, 1, 0},
        {1, 1, 1, 1},
        {1, 1, 1, 1},
        {1, 1, 0, 0}
        };

    
    vector<int> v;
    for(int j = 0; j < 4; j++){
        v.push_back(arr[0][j]);
    }
    int max_area = MAH(v);
    for(int i = 1; i < 4; i++){
        for(int j = 0; j < 4; j++){
            if(arr[i][j] == 0){
                v[j] = 0;
            }else{
                v[j] += arr[i][j];
            }
        }
        // cout << max_area << endl;
        max_area = max(max_area, MAH(v));
    }
    cout << max_area;
}