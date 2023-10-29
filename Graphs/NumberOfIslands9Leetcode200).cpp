/*
Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

 

Example 1:

Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1

  */


Intuition
Use BFS to mark the connected components
All the connected 1s will be a part of single island

Approach
Refer comments used in the code

Complexity
Time complexity:
O(n*m)

Space complexity:
O(n*m)

Code
*/
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        //ans tracks number of islands
        int ans=0;
        
        //All 4 possible directions
        int delR[]={-1,0,1,0};
        int delC[]={0,1,0,-1};

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                //If unvisited land(1), increment ans and mark as visited
                if(grid[i][j]=='1' && vis[i][j]==0){
                    ans++;
                    vis[i][j]=1;
                    queue<pair<int,int>> q;
                    //Push the coordinates into the queue
                    q.push({i,j});

                    //BFS traversal so that we can mark all the connected pieces of land (1s) as visited, as they need not be considered a separate island 
                    while(!q.empty()){
                        int row=q.front().first;
                        int col=q.front().second;
                        q.pop();

                        for(int i=0;i<4;i++){
                            int nrow=row+delR[i];
                            int ncol=col+delC[i];
                            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol]==0 && grid[nrow][ncol]!='0'){
                                vis[nrow][ncol]=1;
                                q.push({nrow,ncol});
                            }


                        }
                    }

                }
            }
        }
        return ans;

        
    }
};
