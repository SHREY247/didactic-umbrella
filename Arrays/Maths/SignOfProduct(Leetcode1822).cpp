/*There is a function signFunc(x) that returns:
1 if x is positive.
-1 if x is negative.
0 if x is equal to 0.
You are given an integer array nums. Let product be the product of all values in the array nums.
Return signFunc(product). 

Example 1:
Input: nums = [-1,-2,-3,-4,3,2,1]
Output: 1
Explanation: The product of all values in the array is 144, and signFunc(144) = 1
*/

//Assign a=1
//Just multiply a with -1 when we get the number less than 0 and with 1 when number is positive
class Solution {
public:
    int arraySign(vector<int>& nums) {
        int a = 1;
        for(auto i : nums){
            if(i==0) return 0;
            else if(i>0) a *=1;
            else a *= -1;
        }
        return a;
    }
};

