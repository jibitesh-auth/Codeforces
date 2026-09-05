//*https://codeforces.com/contest/2242/problem/B

#include <bits/stdc++.h>
using namespace std;

const int INF = 1'000'000'007;

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    vector<int> pref1(n+1);
    vector<int> pref2(n+1);
    for(int i=0; i<n; i++){
        pref1[i+1] = pref1[i] + (a[i] == 1 ? 1 : -1);

        pref2[i+1] = pref2[i] + (a[i] == 3 ? -1:1);

    }

    int mn = INF;
    for(int i=1;i<n; i++){
        if(pref2[i] - mn >=0){
            cout << "YES"<<endl;
            return;
        }
        if(pref1[i] >= 0){
            mn = min(mn,pref2[i]);
        }
    }

    cout << "NO\n";
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}



//*T.C: O(N)
//*S.C: O(N)
//-----------------------------x------------------------------
//*Logic:-
/*we have to break the array into 3 parts such that:-
1. 1st part------> 1 >= 2 & 3
2. 2nd Part------> 1 & 2 >= 3
3. 3rd Part------> Non Empty

We will take x & y:
1 - x, x+1 - y, y+1 - n

calculate the prefix sum
prefix sum of part1: Give 1 as +1 & 2,3 as -1 weight. After that traverse the complete array with n+1 size
prefix sum of part2: Give 3 as -1 and 1,2 as +1 weight. (Do the same)

pref1[x] >= 0, pref2[y] - pref2[x] >= 0  [According to the condition]
We need to choose the x & y along with the satisfying condn

Take the mn = Infinity; check whether the pref1[i] >= 0 if yes then for the same index compare min(mn,pref2[i]) because we need pef2[y] - pref2[x] so to get pref2[x] we are checking pref1 value and inserting that inside pref2 to get that pref2[x]

Next we check if(pref2[y] - pref2[x] >= 0) we return yes

*/























