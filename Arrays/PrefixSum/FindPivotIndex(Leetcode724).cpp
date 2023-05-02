/*Given an array of integers nums, calculate the pivot index of this array.
The pivot index is the index where the sum of all the numbers strictly to the left of the index is equal
to the sum of all the numbers strictly to the index's right.
If the index is on the left edge of the array, then the left sum is 0 because there are no elements to the left.
This also applies to the right edge of the array.
Return the leftmost pivot index. If no such index exists, return -1. */

/*
Example 1:
Input: nums = [1,7,3,6,5,6]
Output: 3
Explanation:
The pivot index is 3.
Left sum = nums[0] + nums[1] + nums[2] = 1 + 7 + 3 = 11
Right sum = nums[4] + nums[5] = 5 + 6 = 11
*/

/*Approach
1: Initialize leftsum[0] as nums[0] and rightsum[n-1] as nums[n-1]
2: Calculate leftsum and rightsum by iterating over the array
3: If leftsum == rightsum, return i else return -1*/

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n=nums.size();
        vector<int>leftsum(n), rightsum(n);
        leftsum[0]=nums[0], rightsum[n-1]=nums[n-1];
        for(int i=1;i<n;i++){
            leftsum[i]=leftsum[i-1]+nums[i];
        }
        for(int i=n-2;i>=0;i--){
            rightsum[i]=rightsum[i+1]+nums[i];
            
        }
         for(int i=0;i<n;i++){
            if(leftsum[i]==rightsum[i])return i;
        }
        return -1;
    }
};
