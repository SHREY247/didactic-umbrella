/*
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.
*/


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> mp;
        int n = nums.size();
        for(int i=0;i<n;i++){
        // if we don't get the key corresponding to difference between target and nums[i] in the map, then add index of nums[i] to the map
            if(mp.find(target-nums[i])==mp.end())
                mp[nums[i]] = i;

         //The key corresponding to difference between the target and nums[i] exists in the map, so return the indices       
            else
                return {i, mp[target-nums[i]]};
        }
        
        return {};
    }
};
