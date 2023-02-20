//Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<int> r,c;
        int m=matrix.size(),n=matrix[0].size();

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    r.push_back(i);
                    c.push_back(j);
                }
            }
        }

        for(auto x:r){
            for(int i=0;i<n;i++){
                matrix[x][i]=0;
            }
        } 

         for(auto x:c){
            for(int i=0;i<m;i++){
                matrix[i][x]=0;
            }
        }           
    }
};








 
