
//*https://codeforces.com/contest/2254/problem/B

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;

        int group = 1,x =0;
        for(int i=1; i<n; i++){
            if(s[i] != s[i-1]){
                group++;
            }
            if(i == n-1){
                break;

            }
            if(s[i] != s[i+1] && s[i] != s[i-1]){
                if(s[i+1] == s[i-1]){
                    x = 2;
                }
                else{
                    x = max(x,1);
                }
            }
        }
        cout << group - x << endl;
    }




    return 0;
}