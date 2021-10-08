#include <iostream>
#include <vector>
using namespace std;

void printArr(int *A, int n)
{
    for(int i = 0; i < n; i++)
        cout<<i<<"->"<<A[i]<<endl;
}

void bellmanFord(vector<vector<int> > adjMatrix, int n, int e, int s)
{
    int dist[n];
    for (int i = 0; i < n; i++)
        dist[i] = INT_MAX;
    dist[s] = 0;

    for (int i = 1; i <= n - 1; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                if (adjMatrix[j][k] != 0)
                {
                    int weight = adjMatrix[j][k];
                    if (dist[j] != INT_MAX && dist[j] + weight < dist[k])
                        dist[k] = dist[j] + weight;
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (adjMatrix[i][j] != 0)
            {
                int weight = adjMatrix[i][j];
                if (dist[i] != INT_MAX && dist[i] + weight < dist[j])
                {
                    cout << "Graph contains negative weight cycle" << endl;
                    return;
                }
            }
        }
    }
    cout<<"Shortest Distance:"<<endl;
    printArr(dist, n);

    return;
}

int main()
{
    int v, e;
    int e1, e2, w;
    cout << "Enter the number of vertices and edges:"<<endl;
    cin >> v >> e;
    vector<vector<int> > adjMatrix( v , vector<int> (v, 0));
    cout << "Enter edges with weight" << endl;
    for (int i = 0; i < e; i++)
    {
        cin >> e1 >> e2 >> w;
        adjMatrix[e1][e2] = w;
    }
    bellmanFord(adjMatrix, v, e, 0);
}