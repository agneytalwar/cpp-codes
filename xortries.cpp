#include<bits/stdc++.h>
using namespace std;
class trienode{
    public:
    trienode* left;
    trienode* right;
    trienode(){
        left=NULL;
        right=NULL;
    }
};
void insert(trienode* head,int n){
    trienode* node=head;
    for(int i=31;i>=0;i--){
        if(((n>>i)&1)==1){
            if(node->right==NULL){
                node->right=new trienode;
            }
            node=node->right;
        }else{
            if(node->left==NULL){
                node->left=new trienode;
            }
            node=node->left;
        }
    }
}
int getxor(trienode* node,int n){
    int curr=0;
    for(int i=31;i>=0;i--){
        if(((n>>i)&1)==1){
            if(node->left){
                curr+=(1<<i);
                node=node->left;
            }
            else node=node->right;
        }else{
            if(node->right){
                curr+=(1<<i);
                node=node->right;
            }
            else node=node->left;
        }
    }
    return curr;
}
int solve(vector<int> &A, vector<int> &B) {
    trienode* head=new trienode;
    for(int i=0;i<A.size();i++){
        insert(head,A[i]); 
    }
    int ans=0;
    for(int i=0;i<B.size();i++){
        int curr=getxor(head,B[i]);
        ans=max(ans,curr);
    }
    return ans;
}
int main(){
    vector<int> A,B;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        A.push_back(x);
    }
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        B.push_back(x);
    }
    int ans=solve(A,B);
    cout<<ans<<endl;
}