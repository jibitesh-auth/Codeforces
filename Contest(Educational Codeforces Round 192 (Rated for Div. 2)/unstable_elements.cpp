#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> arr(n);
        int k;
        cin >> k;
        vector<int> arr1(n);
        int way = 0;
        for(int i=0; i<n; i++){
            cin >> arr[i];
            arr1[i] = arr[i];
        }
        for(int i=0; i<arr.size(); i++){
            if(i==0){
                arr.erase(arr.begin());
                continue;
            }
            if(arr[i] != arr[i-1]){
                arr.erase(arr.begin() + i);
            }
        }
        if(arr.size() == k){
            way++;
        }

        while(arr1[j] )


    }
}