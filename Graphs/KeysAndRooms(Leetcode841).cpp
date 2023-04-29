/*There are n rooms labeled from 0 to n - 1 and all the rooms are locked except for room 0. 
Your goal is to visit all the rooms. However, you cannot enter a locked room without having its key.
When you visit a room, you may find a set of distinct keys in it. Each key has a number on it, denoting which room it unlocks,
and you can take all of them with you to unlock the other rooms.
Given an array rooms where rooms[i] is the set of keys that you can obtain if you visited room i,
return true if you can visit all the rooms, or false otherwise.

Input: rooms = [[1],[2],[3],[]]
Output: true
Explanation: 
We visit room 0 and pick up key 1.
We then visit room 1 and pick up key 2.
We then visit room 2 and pick up key 3.
We then visit room 3.
Since we were able to visit every room, we return true.
*/
/*Approach:

1: Maintain a visited array of size equals room.size() and mark it 0 for all nodes, indicating node hasn't been visited yet
2: Call dfs from the initial node, i.e., Node 0
3: Do dfs in the adjacency list of current node, if they aren't visited
4: In the end, if all visited[i] are 1, return true, else, return false.

Complexity
Time complexity:
O(V+E)

Space complexity:
O(V)
*/

class Solution {
public:
    void dfs(vector<vector<int>>& rooms,vector<int>&visited,int current){
        // mark the node as visited
        visited[current] = 1;

        // Traverse 
        for(int i =0;i<rooms[current].size();i++){
            // if not visited call dfs 
            if(!visited[rooms[current][i]]){
                dfs(rooms,visited,rooms[current][i]);
            }
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<int>visited(n,0);

        dfs(rooms,visited,0);

        for(int i=0;i<n;i++){
            if(visited[i] == 0)
            return false;
        }
        return true;
    }
};
 
