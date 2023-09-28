/*
An image is represented by an m x n integer grid image where image[i][j] represents the pixel value of the image.
You are also given three integers sr, sc, and color. You should perform a flood fill on the image starting from the pixel image[sr][sc].
To perform a flood fill, consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel,
plus any pixels connected 4-directionally to those pixels (also with the same color), and so on. Replace the color of all of the aforementioned pixels with color.
Return the modified image after performing the flood fill.

Input: image = [[1,1,1],[1,1,0],[1,0,1]], sr = 1, sc = 1, color = 2
Output: [[2,2,2],[2,2,0],[2,0,1]]
Explanation: From the center of the image with position (sr, sc) = (1, 1) (i.e., the red pixel), all pixels connected by a path of the same color as the starting pixel
(i.e., the blue pixels) are colored with the new color.
Note the bottom corner is not colored 2, because it is not 4-directionally connected to the starting pixel.

Intuition
Change the color of all adjacent cells that have the same initial color as the starting cell

Approach
1: The floodFill function takes in a 2D vector image, starting row sr, starting column sc, and a target color.

2: It initializes initialColor with the color of the starting cell.

3: It creates a copy of the original image called ans.

4: It defines the possible movements for the algorithm (delRow and delCol arrays), which are up, right, down, and left.

5: It calls the dfs function to start the flood-fill process. The dfs function performs the following steps:

a) Marks the current cell with the new color.

b) Checks all neighboring cells for eligibility for color change based on certain conditions.

c)Recursively calls itself for eligible neighboring cells.

6: Once the dfs function completes, the modified ans grid is returned.

Complexity
Time complexity:
O(N*M): Because in the worst case, every cell is visited

Space complexity:
O(N*M): Because we are making a copy of original image (ans)
*/


class Solution {

private:
    void dfs(int row, int col, vector<vector<int>>& ans, vector<vector<int>>& image, int newColour, int delRow[], int delCol[], int initialColor){
        //Colour the current cell with the new colour
        ans[row][col]= newColour;
        int n=image.size();
        int m=image[0].size();
        for(int i=0;i<4;i++){
            int neighbourRow = row + delRow[i];
            int neighbourColumn= col + delCol[i];
            

            //Colour if all the conditions are satisfied
            //First, neighbour is in within limits
            //Second, neighbour had initialColor in it 
            //Third, neighbour has not been painted with the newColour yet
            if(neighbourRow>=0 && neighbourRow<n && neighbourColumn>=0 && neighbourColumn<m && image[neighbourRow][neighbourColumn]==initialColor && ans[neighbourRow][neighbourColumn]!= newColour){
                dfs(neighbourRow,neighbourColumn,ans,image,newColour,delRow,delCol,initialColor);
            }
        }    
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        //Determine the initial colour
        int initialColor=image[sr][sc]; 
        int newColour=color;
        //Make a copy of the original image
        vector<vector<int>> ans = image;
        //Possible neighbours of the cell
        int delRow[]={-1,0,1,0};
        int delCol[]={0,1,0,-1};
        dfs(sr,sc,ans,image,newColour,delRow,delCol, initialColor);
        return ans;
        
    }
};
