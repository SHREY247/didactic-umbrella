/*
You are given an m x n integer array grid where grid[i][j] could be:

1 representing the starting square. There is exactly one starting square.
2 representing the ending square. There is exactly one ending square.
0 representing empty squares we can walk over.
-1 representing obstacles that we cannot walk over.
Return the number of 4-directional walks from the starting square to the ending square, that walk over every non-obstacle square exactly once.


Example:
Input: grid = [[1,0,0,0],[0,0,0,0],[0,0,2,-1]]
Output: 2
Explanation: We have the following two paths: 
1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2)
2. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2)
*/


class Solution {
    int M, N, eCount=1, res=0;
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        M = grid.size(), N=grid[0].size();
        int x, y;
        for (int i=0; i < M; i++)
            for (int j=0; j<N; j++){
                //x,y indicate starting point indices
                if (grid[i][j] ==1) x= i, y=j;
                else if (grid[i][j] ==0) eCount++;
            }

        DFS(grid, x,y,0);
        return res;        
    }

    void DFS(vector<vector<int>>& g, int i, int j,int count){
        //Out of bound check
        if ( i < 0 || i >= M ||  j < 0 || j >= N || g[i][j] == -1) return;
        
        //If we reach the destination and we walk over every non obstacle square,i.e. count=eCount res++
        if(g[i][j] == 2){
            if (count == eCount) res++;
            return;
        }

        //Makr g[i][j]=-1 so that we can't visit it again and also increment the count
        g[i][j] = -1;
        count++;
        //Do dfs in each direction Bottom,Top,Right,left
        DFS(g,i+1,j,count);
        DFS(g,i-1,j,count);
        DFS(g,i,j+1,count);
        DFS(g,i,j-1,count);

        //Backtracking step: Mark g[i][j] as 0
        g[i][j] = 0;
    }
};

