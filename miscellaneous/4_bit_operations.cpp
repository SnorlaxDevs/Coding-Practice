#include<bits/stdc++.h>
using namespace std;

bool if_kth_set(int n, int k){
    return n & (1 << k - 1);
}

int clear_kth_bit(int n, int k){
    return n & ~(1 << k - 1);
}

int toggle_kth_bit(int n, int k){
    return n ^ (1 << k - 1);
}

int toggle_rightmost_one_bit(int n){
    return n & n-1;
}

int isolate_rightmost_one(int n){
    return n & -n;
}

int isolate_rightmost_zero(int n){
    return ~n & n+1;
}

bool if_2power(int n){
    return (n & n-1) == 0;
}

int count_1_bits(int n){
    int count = 0;
    while(n){
        count++;
        n &= n-1;
    }
    return count;
}
int main(){
    cout << if_kth_set(4, 2) << endl;
    cout << clear_kth_bit(16, 5) << endl;
    cout << if_2power(4) << endl;
    cout << isolate_rightmost_one(10) << endl;
    cout << count_1_bits(15) << endl;

    return 0;
}