//*https://codeforces.com/contest/2242/problem/D

#include <bits/stdc++.h>
using namespace std;

void upd(int& x, int y){
    if(x < y) x = y;

}

void solve(){
    string s,t;
    cin >> s >> t;

    int n = s.size();
    int m = t.size();

    vector<int> ps(n+1), pt(m+1);
    for(int i=0; i<n; i++){
        ps[i+1] = (ps[i] + (s[i] - '0')) % 10;
    }
    for(int i = 0; i < m; i++){
        pt[i + 1] = (pt[i] + (t[i] - '0')) % 10;
    }
        
    
    n++;
    m++;
    if(ps.back() != pt.back()){
        cout << -1 << endl;
        return;
    }

    vector<vector<int>> dp(n+1,vector<int>(m+1));
    for(int i=0; i<=n; i++){
        for(int j=0; j<=m; j++){
            if(i<n) upd(dp[i+1][j],dp[i][j]);

            if(j<m) upd(dp[i][j+1],dp[i][j]);

            if(i<n && j<m && ps[i] == pt[j]) upd(dp[i+1][j+1],dp[i][j]+1);
        }
    }
    cout << dp[n][m] - 1 << endl;

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

//*T.C. = O(N²)
//*S.C. = O(N²) [Because of 2D Vector]

//------------------x---------------------

//*LOGIC:-

/*
Suppose we have 5147 & 44441 we need to convert[Using addition of neighbour(%10)] both of them into same and tell the final string length

5147: 5+1= 6, 4+7= 11%10: 1 ----> 61
44441: 4+4=8[8441], 8+4= 2(12 %10)[241], 2+4 = 6[61] -------> 61

So to solve this we will use prefix sum
5147: 0 5 6 0 7
44441: 0 4 8 2 6 7

Note: 
1) We can only convert both into same, when both of their sum are equal(IN prefix their last should be same)
2) We can trace back the prefix into original by subtracting 
0 5 6 0 7: 5 1 4(10-6) 7----> 5147

We will solve this by finding the LCS(Longest Common Subsequence), here 0 6 7 so tracing back we get 61 whose length is 1(//*Done)

To get the LCS we have to use DP Table---> Make memory

//*DP Table
-> We will use 2D Vector to make DP Table
-> We will make sure that when we get equal value in both the prefix let ps and pt we will do a +1 and store it in diagonal of that index and if not then carry forward, At last we will get the final common LCS[Aparently we will get one more because in prefix 0 and 0 are same so we will do -1]
-> In DP to store the last part we need one more row and column to store it(So always we take 1 more row and columns while creating 2D vector)

              0   1   2   3
            ┌───┬───┬───┬───┐
        0   │ 0 │ 0 │ 0 │ 0 │
            ├───┼───┼───┼───┤
        1   │ 0 │ 1 │ 1 │ 1 │
            ├───┼───┼───┼───┤
        3   │ 0 │ 1 │ 1 │ 2 │
            ├───┼───┼───┼───┤
        4   │ 0 │ 1 │ 1 │ 2 │
            └───┴───┴───┴───┘

Ans: 2-1= 1

*/