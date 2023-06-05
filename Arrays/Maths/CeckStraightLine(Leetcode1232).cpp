/*You are given an array coordinates,
coordinates[i] = [x, y], where [x, y] represents the coordinate of a point. Check if these points make a straight line in the XY plane.

Example:
Input: coordinates = [[1,2],[2,3],[3,4],[4,5],[5,6],[6,7]]
Output: true

*/

/*Approach:
1: Just compute the slopes w.r.t. all the points and check whether they are equal
2: If we find a slope, that is not equal to the slope first calculated, return false, else, return true.
3: For checking equality, don't use division formula for calculating the slope, i.e, (y-y1)/(x-x1) = (y-y2)/(x-x2),
because this may result in divide by zero error, instead cross multiply and then solve*/

class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int n = coordinates.size();

        int x1 = coordinates[0][0];
        int y1 = coordinates[0][1];

        int x2 = coordinates[1][0];
        int y2 = coordinates[1][1];

        for(int i = 2; i < n; i++){
            int x = coordinates[i][0];
            int y = coordinates[i][1];

            // y - y1 / x - x1 != y - y2 / x - x2
            // Division may cause division by zero error.

            if((y - y1) * (x - x2) != (y - y2) * (x - x1)){
                return false;
            } 
        }
        return true;
    }
};

 
