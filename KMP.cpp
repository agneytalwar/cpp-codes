#include<bits/stdc++.h>
using namespace std;
void createlps(int *lps,int n,string &pat){
    int i=1,len=0;
    lps[0]=0;
    while(i<n){
        if(pat[len]==pat[i]){
            lps[i]=len+1;
            i++;
            len++;
        }else{
            if(len!=0){
                len=lps[len-1];
            }else{
                lps[i]=0;
                i++;
            }
        }
    }
}
int main(){
    string s,pat;
    cin>>s>>pat;
    int ans=0;
    int n=s.size(),m=pat.size();
    int lps[m];
    createlps(lps,m,pat);
    int i=0,j=0;
    while(i<n){
        if(s[i]==pat[j]){
            // lps[i]=j+1;
            i++;
            j++;
        }
        else{
            if(j!=0)
                j=lps[j-1];
            else{
                i++;
            }
        }
        if(j==m){
            ans++;
            j=lps[j-1];
        }
    }
    cout<<ans<<endl;
}