/*
The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.
Given an integer n, return the number of distinct solutions to the n-queens puzzle.

Example:
Input: n = 4
Output: 2
Explanation: There are two distinct solutions to the 4-queens puzzle as shown.
*/

class Solution {
public:

   bool isSafePlace(int n, vector<string>& nQueens, int row, int col){
        //Check if Queen already in that particular column?
        for(int i=0; i<n; i++){
            if(nQueens[i][col] == 'Q'){
                return false;
            }
        }
        //Check for queen in left diagonal
        for(int i=row-1, j=col-1; i>=0 && j>=0; i--, j--){
            if(nQueens[i][j] == 'Q'){
                return false;
            }
        }
        //Check for queen in right diagonal
        for(int i=row-1, j=col+1; i>=0 && j<n; i--, j++){
            if(nQueens[i][j] == 'Q'){
                return false;
            }
        }
        return true;
    }
    void solveNQueens(int n, vector<vector<string>>& output, vector<string>& nQueens, int row){
        //Base case: we reach the nth row, meaning we have already placed all queens successfully
        if(row == n){
            output.push_back(nQueens);
            return;
        }

        for(int col=0; col<n; col++){
            //If it is safe to place queen at given row,col place and perform recursion to solve for next queen 
            if(isSafePlace(n, nQueens, row, col)){
                nQueens[row][col] = 'Q';
                solveNQueens(n, output, nQueens, row+1);
                //Backtracking step: Pop the queen back 
                nQueens[row][col] = '.';
            }
        }
    }
    int totalNQueens(int n) {
        vector<vector<string>> output;
        vector<string> nQueens(n , string(n, '.'));
        //solve the problem starting from row=0
        solveNQueens(n, output, nQueens, 0);

        //Reurn the size of output
        return output.size();
        
    }
};

 
