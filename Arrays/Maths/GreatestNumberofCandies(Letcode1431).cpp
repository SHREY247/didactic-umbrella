/*There are n kids with candies. You are given an integer array candies, where each candies[i] represents the number of candies the ith kid has, and an integer extraCandies, denoting the number of extra candies that you have.
Return a boolean array result of length n, where result[i] is true if, after giving the ith kid all the extraCandies, they will have the greatest number of candies among all the kids, or false otherwise.
Note that multiple kids can have the greatest number of candies.

Input: candies = [2,3,5,1,3], extraCandies = 3
Output: [true,true,true,false,true] 
Explanation: If you give all extraCandies to:
- Kid 1, they will have 2 + 3 = 5 candies, which is the greatest among the kids.
- Kid 2, they will have 3 + 3 = 6 candies, which is the greatest among the kids.
- Kid 3, they will have 5 + 3 = 8 candies, which is the greatest among the kids.
- Kid 4, they will have 1 + 3 = 4 candies, which is not the greatest among the kids.
- Kid 5, they will have 3 + 3 = 6 candies, which is the greatest among the kids.
*/


/*
Approach:
1: Create a vector, result, of type bool
2: Maxi variable to calculate the maximum element in the candies array
3: Iterate over the array candies and find the maximum element
4: Check if candies + extraCandies >= maxi, then return true, else return false

Complexity:
Time complexity:
O(N)
*/

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxi=0;
        vector<bool> result;
        maxi=*max_element(candies.begin(),candies.end());
        for(int i=0;i<candies.size();i++){
            if((candies[i]+extraCandies)>=maxi){
                result.push_back(true);
            }
            else{
                result.push_back(false);
            }
        } 
        return result;       
    }
};
