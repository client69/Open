#include<bits/stdc++.h>
using namespace std;

int getminvertex(int *weight,bool *visited,int n)
{
    int minvertex=-1;
    for(int i=0;i<n;i++){
        if(!visited[i] && (minvertex==-1 || weight[i]<weight[minvertex]))
            minvertex=i;
    }
    return minvertex;
}
void prims(int n,int **edges)
{
    int *weight=new int[n];
    int *parent=new int[n];
    bool *visited=new bool[n];
    for(int i=0;i<n;i++){
        weight[i]=INT_MAX;
        visited[i]=false;
    }
    weight[0]=0;
    parent[0]=0;

    for(int i=0;i<n;i++){
        int minvertex=getminvertex(weight,visited,n);
        visited[minvertex]=true;
        for(int j=0;j<n;j++){
            if(!visited[j] && edges[minvertex][j]!=-1){
            if(weight[j]>edges[minvertex][j]){
                weight[j]=edges[minvertex][j];
                parent[j]=minvertex;
            }
        }
        }
    }
    for(int i=1;i<n;i++){
        if(parent[i]<i)
            cout<<parent[i]<<" "<<i<<" "<<weight[i];
        else
            cout<<i<<" "<<parent[i]<<" "<<weight[i];
            cout<<endl;
    }
    delete[] parent;
    delete[] weight;
}
int main()
{
    int n,e;
    cin>>n>>e;
    int **edges=new int*[n];
    for(int i=0;i<n;i++){
        edges[i]=new int[n];
        for(int j=0;j<n;j++){
            edges[i][j]=-1;
        }
    }
    for(int i=0;i<e;i++){
        int s,f,w;
        cin>>s>>f>>w;
        edges[s][f]=w;
        edges[f][s]=w;
    }

    prims(n,edges);
    for (int i=0;i<n;i++){
        delete[] edges[i];
    }
    delete[] edges;
    return 0;
}
