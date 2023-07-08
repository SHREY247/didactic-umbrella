/*Write a program to solve a Sudoku puzzle by filling the empty cells.

A sudoku solution must satisfy all of the following rules:

Each of the digits 1-9 must occur exactly once in each row.
Each of the digits 1-9 must occur exactly once in each column.
Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
The '.' character indicates empty cells.*/

class Solution {
public:
    int getMatNum(int r, int c){
        //To get the submatrix number
        //M0 M1 M2
        //M3 M4 M5
        //M6 M7 M8      
        //Total 9 submatrices present
        return 3*(r/3)+ c/3;
    }
 
 
    bool f(vector<vector<char>> &ma, int r, int c, vector<vector<int>> &rf, vector<vector<int>> &cf, vector<vector<int>> &mf){
        //Base case: If r reaches 9, means we have a valid solution so return true
        if(r==9) return true;
        //If non-empty cell
        if(ma[r][c]!='.'){
            //move to next column
            if(c<8) return f(ma,r,c+1,rf,cf,mf);
            //If on last column, move to first element of next row
            else return f(ma,r+1,0,rf,cf,mf);  
        }
 
        int matNum=getMatNum(r,c);
 
        for(int i=1;i<=9;i++){
            //If row frequency == column frequency == frequency_of_number in matrix == 0, Place that number
            if(!rf[r][i-1] and !cf[c][i-1] and !mf[matNum][i-1]){
                ma[r][c]='0'+i;
                //Update the frequencies
                rf[r][i-1]=cf[c][i-1]=mf[matNum][i-1]=1;
                if(c<8){
                    //Move to next column 
                    if(f(ma,r,c+1,rf,cf,mf)) return true;
                }
                //If on last column, move to next row
                else{
                    if(f(ma,r+1,0,rf,cf,mf)) return true;
                } 

                //Backtracking step
                //Update frequency back to 0 and place a .
                rf[r][i-1]=cf[c][i-1]=mf[matNum][i-1]=0;
                ma[r][c]='.';
            }
        }
 
        return false;
 
    }
 
 
    void solveSudoku(vector<vector<char>>& ma) {
        //rf, cf, mf represent frequency of an element in row, column or submatrix
        vector<vector<int>> rf(9,vector<int>(9,0));
        vector<vector<int>> cf(9,vector<int>(9,0));
        vector<vector<int>> mf(9,vector<int>(9,0));
 
        for(int r=0;r<9;r++){
            for(int c=0;c<9;c++){
                //When you get a non-empty cell
                if(ma[r][c]!='.'){
                    //Store the number in num
                    int num=ma[r][c]-'0';
                    //Update the frequencies of that number 
                    //Update at (num-1) because of 0 indexing
                    //Frequency of 1 will be stored at index 0, and so on..
                    rf[r][num-1]=1;
                    cf[c][num-1]=1;
                    int matNum=getMatNum(r,c);
                    mf[matNum][num-1]=1;
                }
            }
        }
 
        f(ma,0,0,rf,cf,mf);
 
    }
};
