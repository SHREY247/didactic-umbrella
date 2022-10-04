//LEETCODE 240
/*Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix.
This matrix has the following properties:
Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.*/

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
