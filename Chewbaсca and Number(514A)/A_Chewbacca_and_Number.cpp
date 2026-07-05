//Problem Link: https://codeforces.com/contest/514/problem/A

#include<bits/stdc++.h>
using namespace std;

int main(){
    long long num;
    cin >> num;
    string a = to_string(num);
    for(int i=0; i<a.size(); i++){
        int b = a[i] - '0';
        int c = 9 - b;
        if(i == 0 && c == 0){
            continue;
        }
        if(c < b){
            a[i] = c + '0'; //'0'-> 48
        }
    }
    cout << a;
    return 0;

}