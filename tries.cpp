#include<bits/stdc++.h>
using namespace std;
class trienode{
    public:
        trienode* children[26];  
        int num;
        bool isterminal;
        trienode(){
            num=0;
            isterminal=false;
            for(int i=0;i<26;i++){
                children[i]=NULL;
            }
        }
};
// this will be modified as per question
string query(trienode* head,string &s){
    trienode* curr=head;
    int i=0,n=s.size();
    string ans="";
    while(i<n){
        if(curr->num==1 && curr!=head){
            return ans;
        }
        int ch=s[i]-'a';
        ans.push_back(s[i]);
        curr=curr->children[ch];
        i++;
    }
    return ans;
}
void insert(trienode* head,string &s){
    trienode* curr=head;
    int i=0,n=s.size();
    while(i<n){
        int ch=s[i]-'a';
        curr->num++;
        if(!curr->children[ch]){
            curr->children[ch]=new trienode;
        }
        curr=curr->children[ch];
        i++;
    }
    curr->num++;
    curr->isterminal=true;
}
vector<string> prefix(vector<string> &A) {
    trienode* head=new trienode;
    for(int i=0;i<A.size();i++){
        insert(head,A[i]);
    }
    vector<string> ans;
    for(int i=0;i<A.size();i++){
        string curr=query(head,A[i]);
        ans.push_back(curr);
    }
    return ans;
}
int main(){
    int n;
    cin>>n;
    vector<string> A;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        A.push_back(s);
    }
    vector<string> ans=prefix(A);
    for(string k:ans){
        cout<<k<<endl;
    }
}