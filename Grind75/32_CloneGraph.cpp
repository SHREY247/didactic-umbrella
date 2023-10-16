/*
Given a reference of a node in a connected undirected graph.
Return a deep copy (clone) of the graph.
Each node in the graph contains a value (int) and a list (List[Node]) of its neighbors.
class Node {
    public int val;
    public List<Node> neighbors;
}
Test case format:
For simplicity, each node's value is the same as the node's index (1-indexed). For example, the first node with val == 1, the second node with val == 2, and so on. The graph is represented in the test case using an adjacency list.
An adjacency list is a collection of unordered lists used to represent a finite graph. Each list describes the set of neighbors of a node in the graph.
The given node will always be the first node with val = 1. You must return the copy of the given node as a reference to the cloned graph.


Intuition
Use DFS approach to traverse the original graph. During the traversal,create a new node for each encountered node and maintain a mapping between the original nodes and their corresponding clones. When a node's neighbors are processed, check if the clone of the neighbor node has already been created. If so, use the clone from the mapping. Otherwise, recursively explore the neighbor.

Approach
1: Define a helper function dfs that takes a node cur from the original graph and a mapping mp which will store the relationship between original nodes and their clones.
2: In the dfs function:
a) Create a new node clone with the same value as cur.
b) Add the mapping between cur and clone.
c) Initialize an empty vector neighbour to store the cloned neighbors.
d)Iterate through the neighbors of cur.
1) If the neighbor has already been cloned (mp.find(it) != mp.end()), use the clone from the mapping.
2) Otherwise, recursively call dfs on the neighbor to get its clone.
3) Set the neighbors of the clone to the neighbour vector.
4) Return the clone.

3: In the cloneGraph function:
1)Initialize an unordered map mp to store the mapping between original nodes and their clones.
2)Check if node is NULL, and if so, return NULL.
3) Call the dfs function with the original node and the mapping mp.

Complexity
Time complexity:
O(V+E)

Space complexity:
O(V)

Code
*/
class Solution {
public:
Node* dfs(Node* cur,unordered_map<Node*,Node*>& mp)
    {
        vector<Node*> neighbour;
        Node* clone=new Node(cur->val);
        mp[cur]=clone;
            for(auto it:cur->neighbors)
            {
                if(mp.find(it)!=mp.end())   //already in map
                {
                    neighbour.push_back(mp[it]);    
                }
                else
                    neighbour.push_back(dfs(it,mp));
            }
            clone->neighbors=neighbour;
            return clone;
    }
    Node* cloneGraph(Node* node) {
        unordered_map<Node*,Node*> mp;
        if(node==NULL)
            return NULL;
            
        return dfs(node,mp);
    }};
 
