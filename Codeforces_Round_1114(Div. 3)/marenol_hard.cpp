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
        string a,b;
        cin >>a >> b;

        ll ans = 0;
        bool ok = true;

        for(int k =0; k<2; k++){
            vector<int> p1,p2;
            for(int i = k; i<n; i+=2){
                if(a[i] == '1') p1.push_back(i);
                if(b[i] == '1')p2.push_back(i);


            }
            if(p1.size() != p2.size()){
                ok = false;
                break;
            }

            for(int i=0; i<p1.size(); i++){

            ans += abs(p1[i] - p2[i]);
            }


        }
        if(!ok){
            cout << -1 << endl;

        }
        else{
            cout << ans/2 <<endl;
        }
    }



    return 0;
}