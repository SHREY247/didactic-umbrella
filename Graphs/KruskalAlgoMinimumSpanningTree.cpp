/*
Given a weighted, undirected and connected graph of V vertices and E edges. The task is to find the sum of weights of the edges of the Minimum Spanning Tree. 
  Given  adjacency list adj as input parameters . 
Here adj[i] contains vectors of size 2, where the first integer in that vector denotes the end of the edge and the second integer denotes the edge weight.
*/


//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


/*Approach:
1: Sort the edges based upon their weights
2: Edge having smallest weight is picked up, if it doen't form cycle with the tree, include the edge
3: DO till total number of edges becomes N-1, where N is number of nodes
*/

//Detect cycle using union find 
class Solution
{
    public:
    //Function to find sum of weights of edges of the Minimum Spanning Tree.
    int getRoot(int i,vector <int> &parent){
        if(parent[i]==i){
            return i;
        }
        return parent[i]=getRoot(parent[i],parent);
    }
    
    bool find(int i,int j,vector<int> &parent){
        return getRoot(i,parent)==getRoot(j,parent);
    }
    
    int findUnion(int i,int j,int weight,vector<int> &parent,vector<int> &sizeOfGraph){
        if( find(i,j,parent) )return 0;
        
        int par1=getRoot(i,parent);
        int par2=getRoot(j,parent);
        int size1=sizeOfGraph[i];
        int size2=sizeOfGraph[j];
        
        if(size1>size2){
            parent[par2]=par1;
            sizeOfGraph[par1]+=sizeOfGraph[par2];
        }
        else{
            parent[par1]=par2;
            sizeOfGraph[par2]+=sizeOfGraph[par1];
        }
        
      return weight;  
    }
    
 
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector <vector<int>> edges;
        for(int i=0;i<V;i++){
            for(auto it: adj[i])
                edges.push_back({it[1],i,it[0]});
        }
        sort(edges.begin(),edges.end());
        
        vector <int> parent(V);
        vector<int> sizeOfGraph(V,1);
        
        for(int i=0;i<V;i++)
            parent[i]=i;
            
        int total=0;     
        
       
        for(int i=0;i<edges.size();i++){
            total+=findUnion(edges[i][1],edges[i][2],edges[i][0],parent,sizeOfGraph);
        }
        
        
        
       return total; 
        
    }
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends
