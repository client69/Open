#include<bits/stdc++.h>

using namespace std;

void dfs(vector<vector<int> > &edges, bool* visited, int a, int n, stack<int>* s)
{
    visited[a] = true;
    for(int i = 0; i < edges[a].size(); i++)
    {
        if(visited[edges[a][i]] == false)
        {
            dfs(edges, visited, edges[a][i], n, s);
        }
    }
    s->push(a);
}
void dfs2(vector<vector<int> > &redges, bool* visited, int a, int n, vector<int> &v)
{
    visited[a] = true;
    v.push_back(a);
    for(int i = 0; i < redges[a].size(); i++)
    {
        if(visited[redges[a][i]] == false)
        {
            dfs2(redges, visited, redges[a][i], n, v);
        }
    }
}

vector<vector<int> > component(vector<vector<int> > &edges, vector<vector<int> > &redges, bool* visited, int n)
{
    vector<vector<int> > output;
    stack<int>* s = new stack<int>;
    for(int i = 0; i < n; i++)
        if(visited[i] == false)
            dfs(edges, visited, i, n, s);
    for(int i = 0; i < n; i++)
        visited[i] = false;
    while(!s->empty())
    {
        int a = s->top();
        s->pop();
        if(visited[a] == false)
        {
            vector<int> v;
            dfs2(redges, visited, a, n , v);
            output.push_back(v);
        }
    }
    return output;
}

int main()
{
    while(true)
    {
        int n = 0, e = 0;
        cin>>n;
        if(n == 0)
            break;
        cin>>e;
        vector<vector<int> > edges(n), redges(n);
        int a, b;
        for(int i = 0; i < e; i++)
        {
            cin>>a>>b;
            edges[a - 1].push_back(b - 1);
            redges[b - 1].push_back(a - 1);
        }
        bool* visited = new bool[n];
        for (int i = 0; i < n; i++)
        {
            visited[i] = false;
        }
        vector<vector<int> > output = component(edges, redges, visited, n);
        vector<vector<int> > bottoms;
        for (int i = 0; i < output.size(); i++)
        {
            bool flag = true;
            for(int j = 0; j < output[i].size(); j++)
            {
                if(!flag)
                    break;
                int a = output[i][j];
                for(int k = 0; k < edges[a].size(); k++)
                {
                    if(output[i].end() == find(output[i].begin(), output[i].end(), edges[a][k]))
                    {
                        flag = false;
                        break;
                    }
                }
            }
            if(flag)
                bottoms.push_back(output[i]);
        }
        for(int i = 0; i < bottoms.size(); i++)
        {
            for(int j = 0; j < bottoms[i].size(); j++)
            {
                int a = bottoms[i][j];
                cout<<++a<<" ";
            }
            cout<<endl;
        }   
    }
    return 0;
}