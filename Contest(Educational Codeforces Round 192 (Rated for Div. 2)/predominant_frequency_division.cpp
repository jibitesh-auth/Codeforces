#include<bits/stdc++.h>
using namespace std;

int main(){
    unsigned int t;
    
    int z = 0;
    cin >> t;
    int c[t];
    while(t--){
        z++;
        unsigned int n;
        cin >> n;
        if(n < 3){
            cout<<"Wrong Input";
            break;
        }
        int arr[n];
        int count1= 0, count2 = 0, count3 = 0;
        int left=-1, middle=-1;
        bool a = false;
        
        
        for(int i=0; i<n; i++){
            cin >> arr[i];
            if(arr[i] > 3 || arr[i] < 1){
                cout << "Wrong Input";
                return 0;
            }

            if(arr[i] == 1){
                count1++;
            }
            else if(arr[i] == 2){
                count2++;
            }
            else{
                count3++;
            }

            if((count1 >= count2 + count3) && left == -1 && middle == -1){
                left = i;
                count1 =0,count2=0,count3=0;
                
            }
            else if((count1 + count2 >= count3) && left != -1 && middle == -1){
                middle = i;
                count1 =0,count2=0,count3=0;
            }
            else if(((n-1) > middle ) && middle != -1 && left != -1){
                a = true;

            }
            
        }
        if (a){
            c[z-1] = 1;
        }
        else{
            c[z-1] = 0;
        }
    
        //left-> count1 >= count2 + count3
        //middle-> count1 + count2 >= count3
        //right-> non-empty

    }
    for(int i=0; i<z; i++){
        if(c[i]){
            cout<<"YES" << endl;
        }
        else{
            cout<<"NO << endl";
        }

    }

    return 0;
}