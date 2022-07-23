#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,q;
    cin>>n>>q;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int temp=n,maxp2=0;
    while(temp>0){
        temp/=2;
        maxp2++;
    }
    maxp2--;
    int dp[n][maxp2+1];
    for(int i=0;i<=maxp2;i++){
        int pow2=(1<<i);
        for(int j=0;j<=n-pow2;j++){
            if(i==0){
                dp[j][i]=arr[j];
            }
            else{
                dp[j][i]=min(dp[j][i-1],dp[j+pow2/2][i-1]);
            }
        }
    }
    while(q--){
        int a,b;
        cin>>a>>b;
        a--,b--;
        int k=b-a+1;
        int temp=k,maxp2=0;
        while(temp>0){
            temp/=2;
            maxp2++;
        }
        maxp2--;
        int ans;
        if(maxp2!=0)
            ans=min(dp[a][maxp2],dp[b+1-(1<<(maxp2))][maxp2]);
        else ans=dp[a][maxp2];
        cout<<ans<<endl;
    }
}