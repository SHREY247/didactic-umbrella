/*Given an n x n binary matrix grid, return the length of the shortest clear path in the matrix. If there is no clear path, return -1.
A clear path in a binary matrix is a path from the top-left cell (i.e., (0, 0)) to the bottom-right cell (i.e., (n - 1, n - 1)) such that:
All the visited cells of the path are 0.
All the adjacent cells of the path are 8-directionally connected (i.e., they are different and they share an edge or a corner).
The length of a clear path is the number of visited cells of this path.*/

/*Example:
Input: grid = [[0,1],[1,0]]
Output: 2*/

/*Complexity
Time complexity:
O(N^2)

Space complexity:
O(N^2)*/


class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

        int n = grid.size();
        vector<vector<int>> visited(n, vector<int>(n, 0));

        //If top left or bottom right is not 0, return -1
        if(grid[0][0]!=0 || grid[n-1][n-1]!=0){
            return -1;
        }

        //Queue to maintain the possible positions where we can go
        queue<pair<int,int>> q;
        q.push({0,0});
        int res = 0;
        while(!q.empty()){
            int m = q.size();
            for(int i=0; i<m; i++){
                auto [r,c] = q.front();
                q.pop();
                //Check for necessary conditions
                if(r<0 || r>=n || c<0 || c>=n || grid[r][c]==1 || visited[r][c]){
                    continue;
                }
                //Check whether we have reached bottom right
                if(r==n-1 && c==n-1){
                    return res+1;
                }

                //Mark as visited
                visited[r][c] = 1;

                //Moving all 8 possible directions into queue
                q.push({r-1,c-1});
                q.push({r-1,c});
                q.push({r-1,c+1});
                q.push({r,c-1});
                q.push({r,c+1});
                q.push({r+1,c-1});
                q.push({r+1,c});
                q.push({r+1,c+1});
            }
            res++;   
        }
        return -1;
    }
};
