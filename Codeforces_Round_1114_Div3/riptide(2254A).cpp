
//*https://codeforces.com/contest/2254/problem/A

#include <bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        vector<int> v(3);
        for(auto &x : v){
            cin >> x;
        }
        sort(v.begin(), v.end());
        cout << min(v[2] - v[1], v[1] - v[0]) << endl;
        
    }

    return 0;
}