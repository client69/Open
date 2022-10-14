#include<bits/stdc++.h>
using namespace std;

class edge
{
    public:
    int src,dest,weight;
};
bool compare(edge e1,edge e2)
{
    return(e1.weight<e2.weight);
}
int getparent(int v,int*parent)
{
    if(parent[v]==v)
        return v;

    return getparent(parent[v],parent);
}
edge* kruskals(int n,edge *edges,int e)
{
    sort(edges,edges+e,compare);
    int *parent=new int[n];
    for(int i=0;i<n;i++){
        parent[i]=i;
    }
    edge*output=new edge[n-1];
    int count=0;
    int i=0;
    while(count<n-1)
    {
        edge currentedge=edges[i];
        int srcparent=getparent(currentedge.src,parent);
        int destparent=getparent(currentedge.dest,parent);
        if(srcparent!=destparent){

            output[count]=edges[i];
            count++;
            parent[srcparent]=destparent;
        }
        i+=1;
    }
    return output;
}
int main()
{
    int n,e;
    cin>>n>>e;
    edge *edges=new edge[e];
    for(int i=0;i<e;i++){
        int s,d,w;
        cin>>s>>d>>w;
        edges[i].src=s;
        edges[i].dest=d;
        edges[i].weight=w;
    }
    edge* output=kruskals(n,edges,e);
    for(int i=0;i<n-1;i++){
        if(output[i].src<output[i].dest)
            cout<<output[i].src<<" "<<output[i].dest<<" "<<output[i].weight;
        else
             cout<<output[i].dest<<" "<<output[i].src<<" "<<output[i].weight;
        cout<<endl;
    }
    return 0;
}
