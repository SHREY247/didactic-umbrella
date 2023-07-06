/*
Find all valid combinations of k numbers that sum up to n such that the following conditions are true:
Only numbers 1 through 9 are used.
Each number is used at most once.
Return a list of all possible valid combinations. The list must not contain the same combination twice, and the combinations may be returned in any order.
*/

class Solution {

private:
    vector<vector<int>> res;
    //idx tracks index, target the effective sum that we require after taking into consideration nums[i], 
    //temp stores the result temporarily

    void helper(int idx, int target, int k, vector<int> &temp, vector<int> &nums){
        //Base Case
        //If target effectively becomes 0 after considering nums[i] and the size of temp equals k 
        //Push temp into result
        if(target == 0 && temp.size() == k){
            res.push_back(temp);
            return;
        }
        
        //If index exceeds the limits, return
        if(idx >= nums.size()) return;

        //If size of temp exceeds the permissible size, return
        if(temp.size()>k) return;
        
    //Push nums[i] into temp if it is lesser than target and then call all the combinations from index i+1
    //Effective target becomes target-nums[i]
        for(int i=idx; i<nums.size(); i++){
            if(nums[i] <= target){
                temp.push_back(nums[i]);
                helper(i+1, target-nums[i], k, temp, nums);
                //Pop from temp for the case where we don't consider nums[i]
                temp.pop_back();
            }
        }
    }
    
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> nums;
        for(int i=1; i<=9; i++) nums.push_back(i);
        vector<int> temp;
        
        // idx, currSum, target, k, temp 
        helper(0, n, k, temp, nums);
        return res;
    }
};
