/*
Given a sorted array of distinct integers and a target value, return the index if the target is found. 
If not, return the index where it would be if it were inserted in order.
You must write an algorithm with O(log n) runtime complexity.

Example:
Input: nums = [1,3,5,6], target = 5
Output: 2
*/


/*
Approach
1: We would be using binary search to find an element just greater than the target and we would placetarget at the index of that element which we determined
2: This element would be present at low index as there the while loop of binary search would break and low would point to the element just greater than target
3: Return low

Code
*/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
         int low = 0;
        int high = nums.size()-1;
        int mid;
        while(low<=high)
        {
            mid = low + (high-low)/2;
            if(nums[mid]==target)
                return mid;
            else if(nums[mid]<target)
                low = mid+1;
            else
                high = mid-1;
        }
        return low;
        
    }
};
