#include<iostream>
#include<map>
#include<vector>
using namespace std;

void topologicalSort(map<int, vector<int>> graph, int s, vector<bool>& vis)
{
    if(vis[s])
        return ;
    vis[s] = true;
    for(int i=0;i<graph[s].size();i++)
    {
        topologicalSort(graph,graph[s][i],vis);
    }
    cout<<s<<" -> ";
}

int main(){
    int n;
    cin>>n;
    int e;
    cin>>e;
    map<int, vector<int>> graph;
    while(e--)
    {
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
    }
    vector<bool> vis(n+1,false);
    topologicalSort(graph,1,vis);
    return 0;
}