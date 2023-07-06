/*Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates
where the chosen numbers sum to target. You may return the combinations in any order.The same number may be chosen from candidates an
unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.

The test cases are generated such that the number of unique combinations that sum up to target is less than 150 combinations for the given input.

Example:
Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]
Explanation:
2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
7 is a candidate, and 7 = 7.
These are the only two combinations.

*/

class Solution {
public:
    //idx represents index, n is size of candidates, sum represents current sum, temp is temporary vector for pushing the result that we are computing at a time
    void helper(int idx, vector<int>& candidates, int n, int sum, int target, vector<int>& temp,         vector<vector<int>>& ans) {
        //Base case: index becomes equal to n and sum equals target, push temp into ans
        if (idx == n) {
            if (sum == target)
                ans.push_back(temp);
            return;
        }

        //If the effective sum after adding candidates[idx] is in permissible range, add candidates[idx] to sum and push it into temp
        if ((sum + candidates[idx]) <= target) {
            sum += candidates[idx];
            temp.push_back(candidates[idx]);
            //Call the helper function again from the same index because unlimited calls are allowed from one index, just the difference would be that now sum would be changed
            helper(idx, candidates, n, sum, target, temp, ans);
            sum -= candidates[idx];
            //Pop candidates[idx] 
            temp.pop_back();
        }
        
        //Call helper function from  idx+1 if the above if condition is false or we don't consider candidates[idx]
         helper(idx+1, candidates, n, sum, target, temp, ans);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<vector<int>> ans;
        vector<int> temp;
        helper(0, candidates, n, 0, target, temp, ans);
        return ans;
    }
};

 
