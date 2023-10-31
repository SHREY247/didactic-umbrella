/*
You are given an m x n grid where each cell can have one of three values:
0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.
Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.
Example 1:
Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
Output: 4


  Intuition
Use BFS, because we need to rot all those fresh oranges that are at a distance of 1 from the rotted oranges in 1 second.

Approach
1: Initialize variables n and m to store the number of rows and columns in the grid, respectively.
2: Create a queue q to store the coordinates of rotten oranges along with the time taken for them to rot.
3: Initialize a 2D vector vis of size (n x m) to keep track of the state of each cell in the grid. A value of 2 indicates a rotten orange, 0 indicates a fresh orange, and 1 indicates an empty cell.
4: Iterate through the grid, and for each cell:
If it's a rotten orange, push its coordinates into the queue with time 0 and mark it as 2 in vis.
5: Initialize total_time to keep track of the maximum time taken for an orange to rot.
6: Define arrays drow and dcol to represent the possible directions (up, right, down, left).
7: While the queue is not empty, do the following:
a) Pop a rotten orange from the queue and update r, c, and t with its coordinates and time taken to rot.
b) Update total_time with the maximum of total_time and t.
c) Explore the four possible directions
d) Calculate the new coordinates (nrow, ncol) based on the direction.
e) Check if the new coordinates are within the grid bounds and if the cell contains a fresh orange (grid[nrow][ncol] == 1) and has not been visited yet (vis[nrow][ncol] != 2).
f) If the conditions are met, push the new coordinates and update the time by incrementing t.
g) Mark the cell as visited by setting vis[nrow][ncol] = 2.
8: After the loop, iterate through the grid again:
If there's a fresh orange that hasn't been visited, return -1 as it means it can't be rotten.
9: Return total_time, which represents the minimum time required for all oranges to rot.

Complexity
Time complexity:
O(n*m)
Space complexity:
O(n*m)
Code

*/
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        //{{r,c},time} representing the row and column and time to rot
        queue<pair<pair<int,int>, int>> q;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        //Pushing all the rotten orange cells into the queue with time as 0 (as already rottened)
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({{i,j}, 0});
                    vis[i][j]=2;
                }
            }
        }

        int total_time=0;
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        while(!q.empty()){
            int r=q.front().first.first;
            int c=q.front().first.second;
            int t=q.front().second;
            total_time = max(total_time, t);
            q.pop();
            for(int i=0;i<4;i++){
                int nrow= r+drow[i];
                int ncol=c+dcol[i];
                if(nrow>=0 and nrow<n && ncol<m && ncol>=0 && grid[nrow][ncol]==1 && vis[nrow][ncol]!=2 ){
                    q.push({{nrow,ncol},1+t});
                    vis[nrow][ncol]=2;

                }
            }

        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                //If a fresh orange hasn't been rotten
                if(vis[i][j]!=2 && grid[i][j]==1){
                    return -1;
                }
            }
        }
        return total_time;
    }
};
