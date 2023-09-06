/*
Given n, i.e. total number of nodes in an undirected graph numbered from 1 to n and an integer e, i.e. total number of edges in the graph.
Calculate the total number of connected components in the graph. A connected component is a set of vertices in a graph that are linked to each other by paths.
*/

/*Concept:
1: If node is not visited, increment the count by 1
2: Perform dfs from that node
3: Mark all the nodes present in the dfs of that node as visited
4: Now, while checking for nodes, if again an unvisited node is found, that means it is a part of another component
5: Similarly, perform dfs over that node and also increment the count
*/

#include<bits/stdc++.h>
using namespace std;
 
const int N = 1e5+10;
vector<int> graph[N];
bool visited[N];
void dfs(int vertex)
{
    visited[vertex] = true;
    for(int child : graph[vertex])
    {
        if(visited[child]) continue;
        dfs(child);
    }
}
int main()
{
    int n,m;
    cin>>n>>m; //no. of vertex, edges
    for(int i=0; i<m; i++)
    {
        int v1,v2;
        cin>>v1>>v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }
    int connected = 0;
    for(int i=1; i<=n; i++)
    {
        if(visited[i] == false)
        {
            dfs(i);
            connected++;
        }
    }
    cout<<connected<<endl;
}
