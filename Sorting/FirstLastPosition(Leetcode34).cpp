/*Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.
If target is not found in the array, return [-1, -1].
You must write an algorithm with O(log n) runtime complexity.*/

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
            
            if(nums[mid] == target )
            {
                ans[0] = mid;
                r = mid-1;
            }
            else if(nums[mid]<target)
            {
                l = mid+1;
            }
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
            
            if(nums[mid] == target )
            {
                ans[1] = mid;
                 l = mid+1;
            }
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
