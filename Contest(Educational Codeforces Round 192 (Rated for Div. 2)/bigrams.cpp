//*https://codeforces.com/contest/2242/problem/A

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t--){
        bool ok = false;
        int n,x;
        cin >> n;
        int count = 0;
        for(int i=0; i<n; i++){
            cin >> x;
            if(x == 2){
                count++;
            }
            if(x >= 3){
                ok = true;
            }
        }
        if(ok || count > 1){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }


        
    }
    return 0;
}

//*T.C: O(t * k)
//*S.C: O(1)
//----------------X---------------
//*LOGIC:
/*
Suppose we are having 1 2 3 which means a bb ccc
To check for a bigram we need 2 conditions:-
1. one of the no. must be >2 [e.g: 1 2 3 so ccc we can make cc cc[Bigram] ]
2. Atleast 2 of the no should be == 2[e.g: 1 2 2, so here bb cc so we can make bcbc: Bigram]
*/
