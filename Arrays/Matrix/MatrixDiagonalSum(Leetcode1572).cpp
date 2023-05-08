/*Given a square matrix mat, return the sum of the matrix diagonals.
Only include the sum of all the elements on the primary diagonal and all the
elements on the secondary diagonal that are not part of the primary diagonal.

Example:
Input: mat = [[1,2,3],
              [4,5,6],
              [7,8,9]]
Output: 25
Explanation: Diagonals sum: 1 + 5 + 9 + 3 + 7 = 25
Notice that element mat[1][1] = 5 is counted only once.



Approach:
We iterate over the rows of the matrix and add the elements at the current row
and the corresponding columns to the diagonal sums. Finally, we subtract the center 
element of the matrix if the size of the matrix is odd, since it would have been counted
twice in the diagonal sums.
*/

class Solution {
public:
   int diagonalSum(vector<vector<int>>& mat) {
    int n = mat.size();
    int primarySum = 0, secondarySum = 0;
    for (int i = 0; i < n; i++) {
        primarySum += mat[i][i];
        secondarySum += mat[i][n-1-i];
    }
    if (n % 2 == 1) {
        int mid = n / 2;
        secondarySum -= mat[mid][mid];
    }
    return primarySum + secondarySum;
}
};

 
