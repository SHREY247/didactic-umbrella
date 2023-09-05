/*
Consider an undirected graph consisting of  nodes where each node is labeled from  to  and the edge between any two nodes is always of length 6.
  We define node  to be the starting position for a BFS. Given a graph, determine the distances from the start node to each of its descendants and return
  the list in node number order, ascending. If a node is disconnected, it's distance should be .

For example, there are  nodes in the graph with a starting node . The list of , and each has a weight of 6*/


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#include<bits/stdc++.h>
 
class Graph {
    public:
    vector<vector<int>>adj;
        Graph(int n) {
            adj.resize(n+1);
 
        }
 
        void add_edge(int u, int v) {
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
 
        vector<int> shortest_reach(int start) {
            //m represents tital number of nodes
            int m=adj.size();
            //Initialize a visited vector, mark all nodes as unvisited
            vector<int>visited(m,0);
            
            //Pair contains node and distance from source
            queue<pair<int,int>>q;
            //Push into queue, the starting node and distance from itself is 0 
            q.push({start,0}); 
            //Mark the starting node as visited
            visited[start]=1;
            
            
            //Distance vector initialized
            vector<int>dis(m,-1);
            while(!q.empty()){
                pair<int,int>x=q.front();
                q.pop();
                for(int i=0;i<adj[x.first].size();i++){
                        //If the neighbour isn't visited, visit it and add it into queue
                        //Also update the distance as previous distance + 6
                    if(!visited[adj[x.first][i]]){
                        visited[adj[x.first][i]]=1;
                        dis[adj[x.first][i]]=(x.second+6);
                        q.push({adj[x.first][i],x.second+6});
                    }
                }
 
            }

            dis.pop_back();
            return dis;
        }
 
};

int main() {
    int queries;
    cin >> queries;
        
    for (int t = 0; t < queries; t++) {
      
		int n, m;
        cin >> n;
        // Create a graph of size n where each edge weight is 6: 
        Graph graph(n);
        cin >> m;
        // read and set edges
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            // add each edge to the graph
            graph.add_edge(u, v);
        }
		int startId;
        cin >> startId;
        startId--;
        // Find shortest reach from node s
        vector<int> distances = graph.shortest_reach(startId);

        for (int i = 0; i < distances.size(); i++) {
            if (i != startId) {
                cout << distances[i] << " ";
            }
        }
        cout << endl;
    }
    
    return 0;
}
