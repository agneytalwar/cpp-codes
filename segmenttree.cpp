#include<bits/stdc++.h>
using namespace std;
void buildtree(int *arr,int *tree,int si,int ei,int tindex){
    if(si==ei){
        tree[tindex]=arr[si];
        return;
    }
    int mid=si+(ei-si)/2;
    buildtree(arr,tree,si,mid,2*tindex);
    buildtree(arr,tree,mid+1,ei,2*tindex+1);
    tree[tindex]=min(tree[2*tindex],tree[2*tindex+1]);
}
int querytree(int *arr,int *tree,int si,int ei,int ti,int qsi,int qei){
    if(qsi<=si && ei<=qei){
        return tree[ti];
    }else if(ei<qsi || si>qei){
        return INT_MAX;
    }else{
        int mid=si+(ei-si)/2;
        int ans1=querytree(arr,tree,si,mid,2*ti,qsi,qei);
        int ans2=querytree(arr,tree,mid+1,ei,2*ti+1,qsi,qei);
        return min(ans1,ans2);
    }
}
void updatetree(int *arr,int *tree,int si,int ei,int ti,int in,int val){
    if(si==ei){
        tree[ti]=val;
        arr[in]=val;
        return;
    }
    int mid=(si+(ei-si)/2);
    if(in<=mid){
        updatetree(arr,tree,si,mid,2*ti,in,val);
    }else{
		updatetree(arr,tree,mid+1,ei,2*ti+1,in,val);
    }
    tree[ti]=min(tree[2*ti],tree[2*ti+1]);
}
int main(){
    
    // write your code here
    int n,q;
    cin>>n>>q;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int tree[4*n];
    buildtree(arr,tree,0,n-1,1);
    while(q--){
        char ch;
        cin>>ch;
        if(ch=='q'){
            int i,j;
            cin>>i>>j;
            i--,j--;
            int ans=querytree(arr,tree,0,n-1,1,i,j);
            cout<<ans<<endl;
        }else{
            int i,val;
            cin>>i>>val;
            i--;
            updatetree(arr,tree,0,n-1,1,i,val);
        }
    }
    return 0;
}