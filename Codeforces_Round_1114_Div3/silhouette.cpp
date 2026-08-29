#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<ll> b(n);
        map<ll,ll> freq;

        for(int i=0; i<n; i++){
            cin >> b[i];
            freq[b[i]]++;
        }

        if(!freq.count(0)){
            cout << -1 << endl;
            continue;
        }

        map<ll,ll> ans;
        ll prev_shadow = 0, prev_cnt = 0, lst = 0;
        bool ok = true;

        for(auto [cur_shadow, cur_cnt] : freq){
            if(cur_shadow != 0){
                ll diff = cur_shadow - prev_shadow;

                if(diff % prev_cnt !=0){
                    ok = false;
                    break;
                }

                ll u = diff/prev_cnt;
                if(u <= lst){
                    ok = false;
                    break;
                }

                ans[prev_shadow] = u;
                lst = u;
            }
            prev_shadow = cur_shadow;
            prev_cnt = cur_cnt;
        }

        if(!ok){
            cout << -1 << endl;
            continue;
        }

        ans[prev_shadow] = lst+1;
        for(int i =0; i<n; i++) cout << ans[b[i]] << " \n"[i==n-1];


    }

    return 0;
}