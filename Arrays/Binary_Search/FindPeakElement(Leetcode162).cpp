/*
A peak element is an element that is strictly greater than its neighbors.
Given a 0-indexed integer array nums, find a peak element, and return its index. If the array contains multiple peaks, return the index to any of the peaks.
You may imagine that nums[-1] = nums[n] = -∞. In other words, an element is always considered to be strictly greater than a neighbor that is outside the array.
You must write an algorithm that runs in O(log n) time.

Example:
Input: nums = [1,2,3,1]
Output: 2
Explanation: 3 is a peak element and your function should return the index number 2.
*/

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        if(n==1){
            return 0;
        } 
        
        //Corner case: First element can be greater than the second one and hence it can be a peak
        if(nums[0]>nums[1]){
            return 0;
        }   
        //Another Corner case: Last element can be greater than the second last one and hence it can be a peak
        if(nums[n-1]>nums[n-2]){
            return (n-1);
        }    

        int low=1,high=n-2;

        while(high>=low){
            int mid=low + (high-low)/2;

            if(nums[mid]>nums[mid+1] && nums[mid]>nums[mid-1]){
                return mid;
            }

            //Since element present at mid+1 is greater, this element can be a peak so check in the right part
            else if(nums[mid]<nums[mid+1]){
                low=mid+1;
            }
            
            //Otherwise if element at mid-1 is greater so check to the left of it
            else if(nums[mid]<nums[mid-1]){
                high=mid-1;
            }
        }
        return 0;
    }
};
