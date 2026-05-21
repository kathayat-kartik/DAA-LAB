#include<bits/stdc++.h>
using namespace std;
struct Edge{
int u,v,w;
};
bool cmp(Edge a,Edge b){
return a.w>b.w;
}
int findParent(int node,vector<int>& parent){
if(parent[node]==node)
return node;
return parent[node]=findParent(parent[node],parent);
}
void unionSet(int u,int v,vector<int>& parent){
u=findParent(u,parent);
v=findParent(v,parent);
parent[u]=v;
}
int main(){
int V;
cin>>V;
vector<vector<int>> graph(V,vector<int>(V));
vector<Edge> edges;
for(int i=0;i<V;i++){
for(int j=0;j<V;j++){
cin>>graph[i][j];
if(graph[i][j]!=0 && i<j)
edges.push_back({i,j,graph[i][j]});
}
}
sort(edges.begin(),edges.end(),cmp);
vector<int> parent(V);
for(int i=0;i<V;i++)
parent[i]=i;
int totalWeight=0;
for(auto edge:edges){
int u=findParent(edge.u,parent);
int v=findParent(edge.v,parent);
if(u!=v){
totalWeight+=edge.w;
unionSet(u,v,parent);
}
}
cout<<"Maximum Spanning Weight: "<<totalWeight<<endl;
return 0;
}