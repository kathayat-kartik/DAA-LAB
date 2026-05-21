#include<iostream>
#include<vector>
#include<climits>
using namespace std;
struct Edge{
int u,v,w;
};
void printPath(int node,vector<int>& parent){
if(node==-1)
return;
printPath(parent[node],parent);
cout<<node+1<<" ";
}
int main(){
int V;
cin>>V;
vector<vector<int>> graph(V,vector<int>(V));
vector<Edge> edges;
for(int i=0;i<V;i++){
for(int j=0;j<V;j++){
cin>>graph[i][j];
if(graph[i][j]!=0)
edges.push_back({i,j,graph[i][j]});
}
}
int src;
cin>>src;
src--;
vector<int> dist(V,INT_MAX);
vector<int> parent(V,-1);
dist[src]=0;
for(int i=0;i<V-1;i++){
for(auto edge:edges){
if(dist[edge.u]!=INT_MAX &&
dist[edge.u]+edge.w<dist[edge.v]){
dist[edge.v]=dist[edge.u]+edge.w;
parent[edge.v]=edge.u;
}
}
}
for(int i=0;i<V;i++){
printPath(i,parent);
cout<<": "<<dist[i]<<endl;
}
return 0;
}