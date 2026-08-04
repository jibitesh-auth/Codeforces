#include <bits/stdc++.h>
using namespace std;

void solve(string s){
    if(s.length()>2){
        for(int i=1; i<s.length() -2; i++){
            // if(s[i-1] == s[i]){
                if(s[i] != s[i+1]){
                    s.erase(i+1,1);
                    break;
                }
            // }
            // else {
            //     if(s[i] != s[i+1]){
            //         s.erase(i,1);
            //         break;
            //     }
            }
        }
        s.erase(unique(s.begin(),s.end()),s.end());
    
    cout << s.length() << endl;



}



int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s;
        cin >>s;
        solve(s);
    }

    

    return 0;
}