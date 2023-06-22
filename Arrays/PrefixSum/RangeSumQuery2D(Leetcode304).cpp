/*Given a 2D matrix matrix, handle multiple queries of the following type:

Calculate the sum of the elements of matrix inside the rectangle defined by its upper left corner (row1, col1) and lower right corner (row2, col2).
Implement the NumMatrix class:

NumMatrix(int[][] matrix) Initializes the object with the integer matrix matrix.
int sumRegion(int row1, int col1, int row2, int col2) Returns the sum of the elements of matrix inside the rectangle defined by its upper left corner (row1, col1) and lower right corner (row2, col2).
You must design an algorithm where sumRegion works on O(1) time complexity.*/
/*Example:
  Input
["NumMatrix", "sumRegion", "sumRegion", "sumRegion"]
[[[[3, 0, 1, 4, 2], [5, 6, 3, 2, 1], [1, 2, 0, 1, 5], [4, 1, 0, 1, 7], [1, 0, 3, 0, 5]]], [2, 1, 4, 3], [1, 1, 2, 2], [1, 2, 2, 4]]
Output
[null, 8, 11, 12]

Explanation
NumMatrix numMatrix = new NumMatrix([[3, 0, 1, 4, 2], [5, 6, 3, 2, 1], [1, 2, 0, 1, 5], [4, 1, 0, 1, 7], [1, 0, 3, 0, 5]]);
numMatrix.sumRegion(2, 1, 4, 3); // return 8 (i.e sum of the red rectangle)
numMatrix.sumRegion(1, 1, 2, 2); // return 11 (i.e sum of the green rectangle)
numMatrix.sumRegion(1, 2, 2, 4); // return 12 (i.e sum of the blue rectangle)*/

//Using PREFIX SUM Approach


class NumMatrix {
    vector<vector<int>> preSum;
    int n,m;
public:
    //A valid row is one whose indexes are within limits 
    bool checkValid (int i,int j) {
        return i>=0 && i<n && j>=0 && j<m;
    }
    NumMatrix(vector<vector<int>>& matrix) {
        //Calculating the prefix sum matrix
        preSum = matrix;
        n = preSum.size();
        m = preSum[0].size();
        for (int i=1;i<m;i++) preSum[0][i]+=preSum[0][i-1];
        for (int j=1;j<n;j++) preSum[j][0]+=preSum[j-1][0];
        for (int i=1;i<n;i++) {
            for (int j=1;j<m;j++) {
                preSum[i][j] += (preSum[i][j-1]+preSum[i-1][j]-preSum[i-1][j-1]);
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        //Initialize sum to zero
        int sum = 0;
        n = preSum.size();
        m = preSum[0].size();
        if (!checkValid(row1,col1) || !checkValid(row2,col2))
            return sum;
        sum += preSum[row2][col2];
        //Subtract once because this portion gets added twice
        if (checkValid(row2,col1-1)) 
            sum-=preSum[row2][col1-1];
        //Similarly, Subtract this portion once as it got added twice
        if (checkValid(row1-1,col2))
            sum-=preSum[row1-1][col2];
        //This portion got deleted 2 times so we needed to add this up
        if (checkValid(row1-1,col1-1))
            sum+=preSum[row1-1][col1-1];
        return sum;
    }
};
