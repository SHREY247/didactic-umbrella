/*
Given an integer array nums, find the 
subarray
 with the largest sum, and return its sum.

 

Example 1:

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: The subarray [4,-1,2,1] has the largest sum 6.
Intuition
We use Kadane's algorithm. The idea is to traverse through the array, and at each step, we maintain two variables:
currSum - This keeps track of the maximum sum of a subarray ending at the current position.
maxSum - This keeps track of the maximum sum subarray seen so far.

Approach
1: Initialize currSum and maxSum to the first element of the array.
2: Iterate through the array starting from the second element.
3: For each element, update currSum to be the maximum of the current element or the sum of the current element and currSum. This step represents the choice of whether to start a new subarray or continue an existing one.
4: Update maxSum to be the maximum of maxSum and currSum. This step ensures that maxSum always holds the maximum subarray sum seen so far.
5: After the loop, return maxSum as the result.

Complexity
Time complexity:
O(N)

Space complexity:
O(1)

Code
*/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currSum=nums[0];
        int maxSum=nums[0];
        for(int i=1;i<nums.size();i++){
            currSum=max(nums[i],currSum+nums[i]);
            maxSum=max(maxSum,currSum);
        }       
        return maxSum; 
    }
};
