/*Write a program to solve a Sudoku puzzle by filling the empty cells.

A sudoku solution must satisfy all of the following rules:

Each of the digits 1-9 must occur exactly once in each row.
Each of the digits 1-9 must occur exactly once in each column.
Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
The '.' character indicates empty cells.*/

class Solution {
public:
    //To check whether a no is safe to be placed at a particular position
    bool isSafe(int row,int col,char &c,vector<vector<char>>& board){
        for(int i=0;i<9;i++){
            if(board[i][col]==c) //Checking Row
                return false;
            if(board[row][i]==c) //Checking Column
                return false;

            //Checking the subgrids are unique, i.e, All 3x3 Submatrices    
            if(board[3*(row/3)+i/3][3*(col/3)+i%3]==c)
                return false;
        }
        return true;
    }
    bool solve(vector<vector<char>>& board){
        for(int i=0;i<9;i++){ // Traversal through each element
            for(int j=0;j<9;j++){
                if(board[i][j]=='.'){ // If Empty
                    for(char c='1';c<='9';c++){
                        if(isSafe(i,j,c,board)==true){
                            board[i][j]=c;
                            if(solve(board)==true) //Condition Checking
                                return true;
                            else
                                board[i][j]='.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);        
    }
};
