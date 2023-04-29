/*Given a directed acyclic graph (DAG) of n nodes labeled from 0 to n - 1, 
find all possible paths from node 0 to node n - 1 and return them in any order.
The graph is given as follows: graph[i] is a list of all nodes you can visit from node i 
(i.e., there is a directed edge from node i to node graph[i][j]).

Example:
Input: graph = [[1,2],[3],[3],[]]
Output: [[0,1,3],[0,2,3]]
Explanation: There are two paths: 0 -> 1 -> 3 and 0 -> 2 -> 3.
*/
/*Complexity
Time complexity:
O(V+E)

Space complexity:
O(V+E)*/
class Solution {
public:
    void dfs(vector<vector<int>>&graph,vector<vector<int>>& paths,vector<int>path,int start,int destination){
       
        path.push_back(start);
        // Base condition if start equals destination
        //Push the complete path into paths and return
        if(start == destination){
            paths.push_back(path);
            return;
        }


        // traversal in dfs (adjacency list is already given)
        //Traversal will be in adjacency list of that node
        for(auto x:graph[start]){
            dfs(graph,paths,path,x,destination);
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        
        // 2D vector to store the paths.
        vector<vector<int>> paths;
        // to store the path
        vector<int>path;

        int nodes = graph.size();

        if(nodes == 0) return paths;

        // track paths using dfs traversal
        dfs(graph,paths,path,0,nodes-1);

        return paths;
    }
};
