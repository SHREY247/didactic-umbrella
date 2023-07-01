/*Given an integer array nums of unique elements, return all possible subsets (the power set).
The solution set must not contain duplicate subsets. Return the solution in any order.*/

class Solution {
public:
    void helper(int ind,vector<int> &nums,vector<int> &v,vector<vector<int>> &ans){
        //If index = size, push v into ans
        if(ind==nums.size()){
            ans.push_back(v);
            return;
        }
        //Case when we take nums[ind] as a part of subset
        v.push_back(nums[ind]);
        helper(ind+1,nums,v,ans);

        //Case where we don't consider nums[ind] as a part of subset
        v.pop_back();
        helper(ind+1,nums,v,ans);
    }
   
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> v;
        helper(0,nums,v,ans);
        return ans;
    }
};
