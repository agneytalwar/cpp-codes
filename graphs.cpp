#include<bits/stdc++.h>
#define ll long long
using namespace std;
//dijkstra
void dijkstra(vector<vector<pair<int,int>>> &adj,int n,int m){
    set<pair<ll int,ll int>> s;
    vector<bool> vis(n+1);
    vector<ll int> dist(n+1);
    
    for(int i=0;i<=n;i++){
        vis[i]=false;
        dist[i]=1e15;
    }
    s.insert({0,1});
    dist[1]=0;
    vis[1]=true;
    while(!s.empty()){
        auto it=(s.begin());
        pair<ll int,ll int> curr=*it;
        vis[curr.second]=true;
        s.erase(it);
        for(auto child:adj[curr.second]){
            if(vis[child.first])continue;
            if(curr.first+child.second<dist[child.first]){
                s.erase({dist[child.first],child.first});
                dist[child.first]=curr.first+child.second;
                s.insert({curr.first+child.second,child.first});
            }
        }
    }
    for(int i=1;i<=n;i++){
        cout<<dist[i]<<" ";
    }
    cout<<endl;
}
//prims
void prims(vector<vector<pair<int,int>>> &g,int n,int m){
    vector<bool> vis(n+1);
    vector<int> dist(n+1);
    for(int i=0;i<=n;i++){
        vis[i]=false;
        dist[i]=INT_MAX;
    }
    int ans=0;
    set<pair<int,int>> s;
    s.insert({0,1});
    dist[1]=0;
    while(!s.empty()){
        auto it=s.begin();
        auto curr=*it;
        s.erase(it);
        int wt=curr.first,node=curr.second;
        vis[node]=true;
        ans+=wt;
        for(auto iter:g[node]){
            int child=iter.first,w=iter.second;
            if(vis[child])continue;
            if(w<dist[child]){
                s.erase({dist[child],child});
                dist[child]=w;
                s.insert({dist[child],child});
            }
        }
    }
    cout<<ans<<endl;
}
//kruskal
int findpar(int i,vector<int> &par){
    if(par[i]==i)return i;
    return par[i]=findpar(par[i],par);
}
void unionset(int a,int b,vector<int> &par,vector<int> &rank){
    a=findpar(a,par);
    b=findpar(b,par);
    if(rank[a]<rank[b]){
        swap(a,b);
    }
    if(a!=b){
        par[b]=a;
        if(rank[a]==rank[b]){
            rank[a]++;
        }
    }
}
void ksruskal(){
    int n,m;
    cin>>n>>m;
    vector<pair<int,pair<int,int>>> edges;
    vector<int> rank(n+1);
    vector<int> parent(n+1);
    for(int i=0;i<=n;i++){
        rank[i]=0;
        parent[i]=i;
    }
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        edges.push_back({w,{u,v}});
    }
    sort(edges.begin(),edges.end());
    int ans=0;
    for(auto e:edges){
        int w=e.first,u=e.second.first,v=e.second.second;
        if(findpar(u,parent)!=findpar(v,parent)){
            ans+=w;
            unionset(u,v,parent,rank);
        }
    }
    cout<<ans<<endl;
}
//floyd warshall
void floydwarshall(){
    int n,m,q;
    cin>>n>>m>>q;
    ll int arr[n+1][n+1];
    ll int N=1e16;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            if(i==j)arr[i][j]=0;
            else arr[i][j]=N;
        }
    }
    for(int i=0;i<m;i++){
        ll int u,v,w;
        cin>>u>>v>>w;
        arr[u][v]=min(arr[u][v],w);    
        arr[v][u]=min(arr[v][u],w);
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(arr[i][k]!=INT_MAX && arr[k][j]!=INT_MAX){
                    arr[i][j]=min(arr[i][j],arr[i][k]+arr[k][j]);
                }
            }    
        }
    }
    while(q--){
        int u,v;
        cin>>u>>v;
        if(arr[u][v]!=N)
            cout<<arr[u][v]<<endl;
        else cout<<-1<<endl;
    }
}
//kahns
void kahns(vector<vector<int>> &adj,vector<int> &vis,int n){
    int i;
    int indegree[n];
    for(i = 0 ; i <n;i++){
       indegree[i] =0 ;
    }
    for(i =0 ;i <n;i++){
        int j;
        for(j =0 ; j < adj[i].size();j++)indegree[adj[i][j]]++;
    }

    deque<int> dq;
    for(i= 0;i< n;i++){
        if(indegree[i] == 0){dq.push_back(i);vis[i] = 1;}
    }
    vector<int> ans;

    while(dq.size() != 0){
        int node = dq.front();
        ans.push_back(node);
        
        dq.pop_front();
        for(auto it: adj[node]){
            indegree[it]--;
            if(indegree[it] == 0  && vis[it] == 0){
               dq.push_back(it);
               vis[it] = 1;
            }
        }
    }
    
    cout << ans.size() << endl;
}
int main(){

}