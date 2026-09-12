//*https://codeforces.com/contest/2242/problem/C

#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    vector<int> lens;

    int curr = 1;
    for(int i=1; i<n; i++){
        if(a[i] != a[i-1]){
            lens.push_back(curr);
            curr = 1;
        }
        else{
            curr++;
        }
    
    }
    lens.push_back(curr);
    sort(lens.begin(), lens.end());

    int m = (int)lens.size();
    int d = 0;
    int ans = 0;
    int i = 0;
    while(i < m){
        int len = lens[i];
        int x = len - 1;
        int q = m - i;
        int currLen = n - d - x * q;
        if(currLen <= k && (k - currLen) % q == 0){
            ans++;
        }

        int j = i;
        while(j < m && lens[j]== len){
            j++;
        }
        d += (j-i) * lens[i];
        i = j;

    }
    cout << ans << endl;
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
//*T.C: O(n log n)
//O(N^2) is not considered as both while loop moving in only one direction

//*S.C: O(n)

//-------------x--------------

//*Logic:-
/*
Suppose we have 1 1 1 2 2 3 3 3 3 4
we will make blocks 1 1 1 | 2 2 | 3 3 3 3 | 4 : 3 2 4 1
We will either do A: Deletion or B: Duplication to match with target length(K)
Let x = Deletion, so we have to decide what will be the value of x
3 2 4 1: For 3 : x will be 2 as we can at max subtract 2 times (-1) if we did 3 times then dead
For 2: 1, For 4: 3, For 1: 0
x = {0,1,2,3}

It will go -1 from each block because as per question we can either mark the starting or where neighbours are not equal[Each block satisfies it]

q = No of surviving blocks, d = no of element inside dead blocks

For x = 0
3 2 4 1
q = 4, d = 0

cur_n = n - d - x*q : 10 - 0 - 0 = 10

curr_n <= k suppose k = 9(Not possible)

For x = 1
3 2 4 1
2 1 3 0  = 2+1+3+0: 6
q = 3, d = 1

cur_n = n - d - x*q : 10 - 1 - 3 = 6

curr_n <= k (k = 9) -> Possible
So we will move towards B(Duplication) so atmost incrment across all blocks will be 3 as 3 blocks alive and each block +1

6 -> 9 (Correct) or we can use (k-curr_n) % q == 0 
//* We will check across all the x values to get all the possiblities as output

//* In Code : 
We have made our block: 3 2 4 1 and sorted it 1 2 3 4
and then check for each to find x, so x = size - 1 so for 1: 0, 2: 1.....

so for the first: 1 -------> x = 0 so q = 4, d = 0
second: 2 ------> x = 1 [ that doesnot means we are running on each element it is for whole array -1  so the first one will be deleted i.e, x >= any block size will be deleted] so q = 3, d = 1

Now the logic to find d is unique we are also handling the case for duplicate block size
we are doing j = i( to keep a pointer )
then we are checking inside a while loop : j < m and lens[j] = len(To check duplicate like the i pointer to all the j pointer) and increase j++ 

and then do (j-i) * lens[i] so that we will get what is being delted the d value



*/