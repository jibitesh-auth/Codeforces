//Problem Link: https://codeforces.com/problemset/problem/282/A

#include <bits/stdc++.h>
using namespace std;

int main(){
    int x = 0;
    int y;
    cin >> y;
    for(int i = 0; i<y; i++){
        string a;
        cin >> a;
        if(a[1] == '+'){
            x++;
        }
        else{
            x--;
        }
    }
    cout << x << endl;
    return 0;
    



}

//other way

// #include <bits/stdc++.h>
// using namespace std;
// int main(){
//     int n;
//     cin>>n;
//     int x=0;
//     for(int i=0;i<n;i++){
//         string v;
//         cin>>v;
//         if(v=="X++" || v=="++X"){
//             x++;
//         }
//         else {
//             x--;
//         }
//     }
//     cout<<x;

//     return 0;
// }