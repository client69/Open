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
// i have made a quite simple algorithm 
#include<bits/stdc++.h>
using namespace std;
#define n 6
int minvertex(vector<int>&value,vector<bool> &mst){
    int min=INT_MAX;
    int vertex;
    for(int i=0;i<n;i++){
        if(mst[i]==false && value[i]<min){
            min=value[i];
            vertex=i;
        }
    }
    return vertex;
}
void find(int graph[n][n]){
   vector<bool>mst(n,false);
    vector<int>value(n,INT_MAX);
    int parent[n]={-1};
    parent[0]=-1;
    value[0]=0;
    for(int i=0;i<n-1;i++){
        int u=minvertex(value,mst);
        mst[u]=true;
        for(int j=0;j<n;j++){
            if(graph[u][j]!=0 && mst[j]==false && graph[u][j]<value[j]){
                value[j]=graph[u][j];
                parent[j]=u;
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<"U->V: "<<parent[i]<<"->"<<i<<"  wt = "<<graph[parent[i]][i]<<"\n";
    }
}
int main(){
    int mat[n][n]={ {0, 4, 6, 0, 0, 0},
						{4, 0, 6, 3, 4, 0},
						{6, 6, 0, 1, 8, 0},
						{0, 3, 1, 0, 2, 3},
						{0, 4, 8, 2, 0, 7},
						{0, 0, 0, 3, 7, 0} };
        
            find(mat);
}
