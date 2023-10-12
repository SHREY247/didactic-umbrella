/*
Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.
The distance between two adjacent cells is 1.
Example 1:
Input: mat = [[0,0,0],[0,1,0],[0,0,0]]
Output: [[0,0,0],[0,1,0],[0,0,0]]



  Intuition
Use BFS approach to traverse the matrix and calculate the distances.

Approach
1: Initialization:
Create two matrices (vis and dist) of the same size as the input matrix mat.
Initialize a queue q to perform BFS.

2: BFS Initialization:
Traverse the input matrix mat.
If a cell contains a 0, add its coordinates and set steps to 0 to the queue q. Mark the cell as visited.
If a cell contains a non-zero value, mark it as unvisited.

3: BFS Loop:
While the queue q is not empty, do the following:
Dequeue a cell's coordinates (row, col) and the number of steps taken (steps).
Update the dist matrix at the current coordinates with the number of steps taken.
Explore the 4 neighboring cells (up, down, left, right).
If a neighboring cell is within the bounds of the matrix and has not been visited yet, mark it as visited, enqueue its coordinates, and increment steps by 1.

4: Return Distance Matrix:
After the BFS is complete, the dist matrix contains the shortest distances from each cell to the nearest zero.

Complexity
Time complexity:
O(n*m)

Space complexity:
O(n*m)

Code
*/
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size(); 
	    int m = mat[0].size(); 
	    // visited and distance matrix
	    vector<vector<int>> vis(n, vector<int>(m, 0)); 
	    vector<vector<int>> dist(n, vector<int>(m, 0)); 
	    // <coordinates, steps>
	    queue<pair<pair<int,int>, int>> q; 
	    // traverse the matrix
	    for(int i = 0;i<n;i++) {
	        for(int j = 0;j<m;j++) {
	            // start BFS if cell contains 0
	            if(mat[i][j] == 0) {
	                q.push({{i,j}, 0}); 
	                vis[i][j] = 1; 
	            }
	            else {
	                // mark unvisited 
	                vis[i][j] = 0; 
	            }
	        }
	    }
	    
	    int delrow[] = {-1, 0, +1, 0}; 
	    int delcol[] = {0, +1, 0, -1}; 
	    
	    // traverse till queue becomes empty
	    while(!q.empty()) {
	        int row = q.front().first.first; 
	        int col = q.front().first.second; 
	        int steps = q.front().second; 
	        q.pop(); 
	        dist[row][col] = steps; 
	        // for all 4 neighbours
	        for(int i = 0;i<4;i++) {
	            int nrow = row + delrow[i]; 
	            int ncol = col + delcol[i]; 
	            // check for valid unvisited cell
	            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m 
	            && vis[nrow][ncol] == 0) {
	                vis[nrow][ncol] = 1; 
	                q.push({{nrow, ncol}, steps+1});  
	            }
	        }
	    }
	    // return distance matrix
	    return dist; 
	}                
};
