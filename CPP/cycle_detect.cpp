#include<bits/stdc++.h>
using namespace std;

class Graph
{
    int V;
    vector< vector<int> >adj;
    bool isCyclicUtil(int v,vector<bool> &visited,int parent);

public:
    Graph(int V);
    void addEdge(int v,int w);
    bool isCyclic();
};

Graph::Graph(int V)
{
    this->V=V;
    adj=vector< vector<int> >(V);
}

void Graph::addEdge(int v,int w)
{
    adj[v].push_back(w);
    adj[w].push_back(v);
}

bool Graph::isCyclicUtil(int v,vector<bool> &visited,int parent)
{
    visited[v]=true;
    vector<int>::iterator i;
    for(i=adj[v].begin();i!=adj[v].end();++i)
    {
        if(!visited[*i])
        {
            if(isCyclicUtil(*i,visited,v)) return true;
        }
        else if(*i!=parent) return true;
    }
    return false;
}

bool Graph::isCyclic()
{
    vector<bool> visited(V);
    for(int i=0;i<V;++i)
    {
        visited[i]=false;
    }
    for(int u=0;u<V;++u)
    {
        if(!visited[u])
        {
            if(isCyclicUtil(u,visited,-1))
            {
                return true;
            }
        }
    }
    return false;

}

int main()
{
    int n,e,a,b;
    cout<<"Enter number of nodes:"<<endl;
    cin>>n;
    cout<<"Enter number of edges:"<<endl;
    cin>>e;
    Graph g(n);
    cout<<"Enter edges:"<<endl;
    for(int i=0;i<e;++i){
        cin >> a >> b;
        g.addEdge(a,b);
    }
    g.isCyclic()? cout << "Cycle detected!\n":
                  cout << "No cycle detected!\n";
    return 0;
}


/*

------ OUTPUT 1: ------

Enter number of nodes:
5
Enter number of edges:
5
Enter edges:
0 1
1 2
2 3
2 4
3 4
Cycle detected!

Nodes: 0,1,2,3,4

                0
               /
              1----2
                  / \
                 3---4


Edges: {0,1}, {1,2}, {2,3}, {2,4}, {3,4}.

Cycle:             2
                  / \
                 3---4

Cycle detected.



----- OUTPUT 2: -----


Enter number of nodes:
5
Enter number of edges:
4
Enter edges:
0 1
1 2
2 3
2 4
No cycle detected!

Nodes: 0,1,2,3,4

            0----1
                 |
                 |
                 2
                / \
               3   4

Edges: {0,1}, {1,2}, {2,3}, {3,4}.

Graph doesn't contain a cycle.




*/
//dfs cycle detection 
//directedd graph 
#include<bits/stdc++.h>
using namespace std;
void make(vector<int>v[],int x,int y){
   v[x].push_back(y);

}
bool cycle(vector<int>v[],int i,bool visted[],bool stk[]){
   if(visted[i]==false){
       visted[i]=true;
       stk[i]=true;
       for(auto x: v[i]){
           if(visted[x]==false && cycle(v,x,visted,stk)){
               return true;
           }
           else if(visted[x]==true && stk[x]==true){
               return true;
           }
       }
   }
   stk[i]=false;
    return false;
}
bool iscyclic(vector<int>v[],int n){
   bool visted[n]={false};
   bool stk[n]={false};
   for(int i=0;i<n;i++){
       if(cycle(v,i,visted,stk)==true){
           return true;
       }
       
   }
   return false;
}
int main(){
    int n;
    cin>>n;
    vector<int>v[n];
    int edges;
    cin>>edges;
    while(edges--){
        int x,y;
        cin>>x>>y;
        make(v,x,y);
    }
    if(iscyclic(v,n)){
        cout<<"yes";
    }
    else{
        cout<<"no";
    }
    
}
