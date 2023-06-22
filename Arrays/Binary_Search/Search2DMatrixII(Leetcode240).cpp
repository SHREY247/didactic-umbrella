/*Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:

Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.*/

/*Input: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 5
Output: true*/

/*Approach:
  1: Start searching from arr[0][n-1]
2: If target equals arr[0][n-1] return true, else if target is greater, then just increment i and check for target in next row as target can't be present in i^th row since it is sorted
3: Similarly, if target is smaller decrement j and check within that row
4: In this way, we optimize our search and decrease its time complexity
5: Return false, if target is not found*/


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

       int i=0;
       int j=matrix[0].size()-1;
       int n=matrix.size();

       while(i<n and j>=0){

           if(matrix[i][j]==target){

               return true;

           }else if(target>matrix[i][j]){

               i++;

           }else{

               j--;

           }

       }

        return false;

    }

};
