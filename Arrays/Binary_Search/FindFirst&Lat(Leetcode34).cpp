/*
Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.
If target is not found in the array, return [-1, -1].
You must write an algorithm with O(log n) runtime complexity.


Example:
Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
*/

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size()-1;
        vector<int>ans(2,-1);
        //For 1st position
        while(l <= r)
        {
            int mid = r+(l-r)/2;
            
            //if nums[mid]==target, insert mid into ans and check to the left of mid whether there is an occurence even before mid or not
            if(nums[mid] == target )
            {
                ans[0] = mid;
                r = mid-1;       
            }

            //if target is greater than element at mid, check to the right of mid
            else if(nums[mid]<target)
            {
                l = mid+1;
            }

            //if target is smaller than element at mid, check to the left of mid
            else
            {
                r = mid-1;
            }
        }


        //For last position
        l=0,r = nums.size()-1;
        while(l <= r)
        {
            int mid = r+(l-r)/2;
            
            //i nums[mid] equals target then insert mid into ans[1] and check for an occurence after mid
            if(nums[mid] == target )
            {
                ans[1] = mid;
                 l = mid+1;
            }
            //Similarly, check for target and update indexes as done above 
            else if(nums[mid]<target)
            {
                l = mid+1;
            }
            else
            {
                r = mid-1;
            }
        }
        return ans;
        
    }
};

