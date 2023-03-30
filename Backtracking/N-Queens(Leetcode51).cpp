/*The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.*/


class Solution {
private: 
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
        if(row == n){
            output.push_back(nQueens);
            return;
        }
        for(int col=0; col<n; col++){
            if(isSafePlace(n, nQueens, row, col)){
                nQueens[row][col] = 'Q';
                solveNQueens(n, output, nQueens, row+1);
                nQueens[row][col] = '.';
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> output;
        vector<string> nQueens(n , string(n, '.'));
        solveNQueens(n, output, nQueens, 0);
        return output;
    }
};
