#include <bits/stdc++.h>
using namespace std;
int main(){
    unsigned int t;
    cin>>t;
    unsigned int k;
    string st[t];
    for(int i=0;i<t;i++){
        cin>>k;
        int s=0;
        unsigned int ar[k];
       
        for(int j=0;j<k;j++){
            cin>>ar[j];
            s+=ar[j];    
        }
        if(s>=(k+2)){
            st[i]="Yes";
        }
        else{
            st[i]="No";
        }
    }
    for(int i=0;i<t;i++){
        cout<<st[i]<<endl;
    }
}
 
 
 
 
 
 