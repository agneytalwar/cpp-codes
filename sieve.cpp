#include<bits/stdc++.h>
using namespace std;
int main(){
    
    // write your code here
    int n;
    cin>>n;
    bool arr[n+1];
    for (int i = 0; i <= n; i++)
    {
        arr[i]=true;
    }
    arr[0]=false;
    arr[1]=false;
    for(int i=2;i*i<=n;i++){
        if(arr[i]){
            for(int k=i*i;k<=n;k+=i){
                arr[k]=false;
            }
        }
    }
    //printing
    for(int i=0;i<=n;i++){
        if(arr[i])cout<<i<<" ";
    }
}