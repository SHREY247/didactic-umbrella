/*There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.*/

class Solution {
public:
    //Use mathematical concepts 
    //We have to make (n-1) right moves and (m-1) down moves  
    //Total ways: (n-1 + m-1)!/(n-1)! (m-1)!
    //(n-1) of type 1 and (m-1) of type 2 as we do in maths
    //This is just n+m-2 C n-1 

    int uniquePaths(int m, int n) {
        long ans = 1;
        for(int i = m+n-2, j = 1; i >= max(m, n); i--, j++) 
            ans = (ans * i) / j;
        return ans;
    }
};
