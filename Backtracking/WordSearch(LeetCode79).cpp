/*Given an m x n grid of characters board and a string word, return true if word exists in the grid.
The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring.
The same letter cell may not be used more than once.
Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
Output: true
*/

class Solution {
public:
    
    bool search(int index, int i, int j ,vector<vector<char>>& board, string word)
    { 
      //If index reaches word size, return true
      if(index == word.size())
      {
          return true;
      }
      //If i or j is out of boundary
      if(i<0 or j<0 or i>=board.size() or j>=board[0].size())
      {
          return false;
      }
      bool ans = false;
     if(word[index] == board[i][j])
     {   
         //If the above condition is true mark * to represent that the cell is visited
         board[i][j] = '*';
         
         ans = search(index+1,i+1,j,board,word) or 
               search(index+1,i,j+1,board,word) or
               search(index+1,i-1,j,board,word) or
               search(index+1,i,j-1,board,word);


        //Backtracking step: Put the word back instead of *
        board[i][j] = word[index];
     }
        
     return ans;   
    }
    
    
    
    
    bool exist(vector<vector<char>>& board, string word) {
      int m = board[0].size();
      int n = board.size();
      int index = 0; 
      bool ans = false;
     
      for(int i=0; i<n ;i++)
      {
          for(int j = 0; j<m; j++)
          {
              if(word[index] == board[i][j])
              {
                if(search(index,i,j,board,word))  
                {
                    return true;
                }
              }
          }
      }
        return ans;
    }
};
