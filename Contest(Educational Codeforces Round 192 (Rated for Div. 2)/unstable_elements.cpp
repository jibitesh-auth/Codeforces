// #include <bits/stdc++.h>
// using namespace std;
// int main(){
//     unsigned int t;
//     cin>>t;
//     while(t--){
//         int n,k;
//         cin>>n>>k;
//         vector<int> arr;
//         vector<int> v;
//         for(int i=0;i<n;i++){
//             int x;
//             cin>>x;
//             arr.push_back(x);
//             if(i==0 || (arr[i]!=arr[i-1])){
//                 v.push_back(i);
//             }
//         }
//         int c=0;
//         while(v.size()!=0){
//             int r=rand()%2;
//             switch (r)
//             {
//             case 0:
//                 for(int i=(int)v.size()-1;i>=0;i--){
                    
//                        arr.erase(arr.begin()+v[i]);
                       
                       
                    
//                 }
//                 v.clear();
//                 for(int i=0;i<arr.size();i++){
//                     if(i==0 || (arr[i]!=arr[i-1])){
//                         v.push_back(i);
//                     }
//                 }

               
//                 break;
            
//             case 1:
//                 for(int i=(int)v.size()-1;i>=0;i--){
                  
//                        arr.insert(arr.begin()+v[i],arr[v[i]]);
                       
                    
//                 }
//                 v.clear();
//                  for(int i=0;i<arr.size();i++){
//                     if(i==0 || (arr[i]!=arr[i-1])){
//                         v.push_back(i);
//                     }
//                 }
//                 break;
//             }
//             if(arr.size()==k){
//                 c++;
//             }
//         }
//         cout<<c;
        



//     }
//     return 0;
// }




#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<int> c(n + 1, 0);

    for (int i = 0; i < n;) {
        int j = i;
        while (j < n && a[j] == a[i])
            j++;

        c[j - i]++;
        i = j;
    }

    long long ans = 0;
    long long s1 = 0;
    long long s2 = 0;

    for (int i = n; i >= 1; i--) {
        s1 += c[i];
        s2 += s1;

        if (c[i] && k >= s2 && (k - s2) % s1 == 0)
            ans++;
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
        solve();

    return 0;
}