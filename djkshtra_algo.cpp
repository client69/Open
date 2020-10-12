#include<bits/stdc++.h>
using namespace std;
int getminvertex(int *dist,bool *visited,int n)
{
    int minvertex=-1;
    for(int i=0;i<n;i++){
        if(!visited[i] && (minvertex==-1 || dist[i]<dist[minvertex]))
            minvertex=i;
    }
    return minvertex;
}
void djkshtra(int n,int **edges,int src)
{
    bool *visited=new bool[n];
    int *dist=new int[n];
    for(int i=0;i<n;i++){
        visited[i]=false;
        dist[i]=INT_MAX;
    }
    dist[src]=0;
    for(int i=0;i<n-1;i++){
        int mindistvert=getminvertex(dist,visited,n);
        visited[mindistvert]=true;
        for(int j=0;j<n;j++){
            if(!visited[j] && edges[mindistvert][j]!=0){
                if(dist[j]>dist[mindistvert]+edges[mindistvert][j]){
                    dist[j]=dist[mindistvert]+edges[mindistvert][j];

                }
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<i<<":"<<dist[i];
        cout<<endl;
    }
}
int main()
{
    int n,e;
    cin>>n>>e;
    int **edges=new int*[n];
    for(int i=0;i<n;i++){
        edges[i]=new int[n];
        for(int j=0;j<n;j++){
            edges[i][j]=0;
        }
    }
    for(int i=0;i<e;i++){
        int s,f,w;
        cin>>s>>f>>w;
        edges[s][f]=w;
        edges[f][s]=w;
    }
    djkshtra(n,edges,0);
    return 0;
}
