// #include <bits/stdc++.h>
// using namespace std;

// void solve(int a,int b, int c){
//     int rounds = 0;
//     while(true){
//         if(a == b || a == c || b == c){
//             break;
//         }
//         else{
//             rounds++;
//             int m = max({a,b,c});
//             int l = min({a,b,c});
//             if(m == a){
//                 a--;
//             }
//             else if(m == b){
//                 b--;
//             }
//             else{
//                 c--;
//             }

//             if(l == a){
//                 a++;
//             }
//             else if(l == b){
//                 b++;
//             }
//             else{
//                 c++;
//             }


//         }
//     }
//     cout << rounds<< endl;
// }

// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     int n,a,b,c;
//     cin >> n;
//     for(int i = 0; i<n; i++){
//         cin >>a >> b>>c;
//         solve(a,b,c);

//     }


//     return 0;
// }


//------------------x----------------


#include <bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        vector<int> v(3);
        for(auto x : v){
            cin >> x;
        }
        sort(v.begin(), v.end());
        
    }
    //Hello

    


    return 0;
}