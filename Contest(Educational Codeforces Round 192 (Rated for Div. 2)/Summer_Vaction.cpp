#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int arr[n];
    int arr1[n];
    
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    for(int i=n-1; i>=0; i--){
        int m= 0;
        if(i != n-1){
            for(int j=i; j<n; j++){
                if(m < arr[j]){
                    m += arr[j];
                }
                else{
                    m -=arr[j];
                    
                }
            }
            arr1[n-i-1] = m;
           

        }
        else{
            if(m < arr[i]){
                m = arr[i];
            }
            arr1[0] = m;
        }
       

            
            
    }

    for(int a: arr1){
        cout << a<< " ";
    }

}

