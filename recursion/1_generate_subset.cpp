#include<bits/stdc++.h>
using namespace std;

void subsets(string ip, string op){
    if(ip.length() == 0){
        cout << op << endl;
        return;
    }
    string op1 = op;
    string op2 = op;
    op2.push_back(ip[0]);
    ip.erase(ip.begin() + 0);
    subsets(ip, op1);
    subsets(ip, op2);
}

int main(){
    string s = "abc";
    subsets(s, "");
    return 0;
}