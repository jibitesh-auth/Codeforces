#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n, curr = 0;
    cin >> n;
    multiset<int> b;
    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        b.insert(x);
    }

    vector<int> ans(n);
    for(int i=0; i<n; i++){
        auto it = b.lower_bound(1-curr);
        if(it == b.end()) return void(cout << -1 << '\n');
        curr+=*it;
        b.erase(it);
        ans[i] = curr;

    }
    for(int i=0; i<n; i++) cout << ans[i] << " \n"[i==n-1];
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--) solve();
    return 0;


}

//*T.C: O(logn) + O(logn) + O(n) : O(nlogn)

/*Multi set has T.C: O(logn)*/

//*S.C: O(n)