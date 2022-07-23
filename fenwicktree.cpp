#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll int sum(ll int *bit,int i){
    ll int sum=0;
    for(int k=i;k>0;k-=(k&(-k))){
        sum+=bit[k];
    }
    return sum;
}
void update(ll int * bit,ll int *arr,int index,int diff,int n){
    // int diff=val-arr[index-1];
    for(int i=index;i<=n;i+=(i&(-i))){
        bit[i]+=diff;
    }
}
void solve() {
    int n,q;
    cin>>n>>q;
    ll int arr[n];
    ll int bit[n+1];
    for(int i=0;i<=n;i++){
        bit[i]=0;
    }
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        update(bit,arr,i+1,x,n);
        arr[i]=x;
    }
    // for(int i=1;i<=n;i++){
    //     cout<<sum(bit,i)<<endl;
    // }
    while(q--){
        int ch;
        cin>>ch;
        if(ch==1){
            int k,u;
            cin>>k>>u;
            update(bit,arr,k,u-arr[k-1],n);
            arr[k-1]=u;
        }else{
            int a,b;
            cin>>a>>b;
            ll int ans=sum(bit,b);
            if(a!=1){
                ans-=sum(bit,a-1);
            }
            cout<<ans<<endl;
        }
    }
}
 
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
 
    int t = 1;
    while(t--) {
      solve();

}
 
    return 0;
}
 
