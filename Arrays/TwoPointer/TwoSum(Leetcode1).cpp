/*
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
You can return the answer in any order.
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        //Push the value and index in vector vp
        vector<pair<int,int>>vp;
        for(int i=0; i<n; i++){
            vp.push_back({nums[i],i});
        }
        //Sort the vector
        sort(vp.begin(), vp.end());
        int i = 0, j = n-1;
        while(i < j){
            int sum = vp[i].first + vp[j].first;
            //if sum equals target return the indices
            if(sum == target) return {vp[i].second,vp[j].second};
            //If sum is less than target, increment i necause that would increase our sum
            if(sum < target) i++;
            //If sum is less than target, decrement j, that way sum would decrease and we can check whether it becomes equal to target
            else j--;
        }
        return {};
    }
};
