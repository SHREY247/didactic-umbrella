/*
Given an array of distinct integers candidates and a target integer target, 
return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.
The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequencyof at least one of the chosen numbers is different.
The test cases are generated such that the number of unique combinations that sum up to target is less than 150 combinations for the given input.
Example 1:

Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]
Explanation:
2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
7 is a candidate, and 7 = 7.
These are the only two combinations.
*/

Intuition
Use recursion and backtracking to explore all the possible combinations of elements that can sum up to the target value

Approach
1: The combinationSum function initializes an empty ans vector to store the resulting combinations and starts the solve function with initial parameters: i = 0 (starting index), arr as the candidates array, temp as an empty vector to store the current combination being formed, and target as the target sum.

2: The solve function performs a backtracking search through the candidates array:
a) If the target becomes 0, it means a valid combination is found, and it's added to the ans vector.
b) If target becomes negative, or i reaches the end of the array, it stops that particular branch of exploration.
c) It explores two possibilities at each step: either excluding the current element (solve(i+1, arr, temp, target)) or including the current element (temp.push_back(arr[i]); solve(i, arr, temp, target-arr[i]);). After exploring both possibilities, it removes the last element (temp.pop_back()) to backtrack and explore other combinations.

3:Finally, it returns the ans vector containing all the valid combinations.

Time Complexity
O(2^n), representing maximum number of combinations

Space Complexity
O(2^n + n)
The ans vector stores all the valid combinations, which can take up to O(2^n) space in the worst case. Additionally, the recursion stack space used during backtracking can also go up to O(n) in the worst case, where 'n' is the length of the candidates array. The temp vector used for storing each combination can take up to O(n) space as well.

Code
class Solution {
public:
    vector<vector<int>> ans;
    void solve(int i, vector<int>& arr, vector<int> &temp, int target){
        if(target==0){
            ans.push_back(temp);
            return;
        }

        if(target<0){
            return;
        }

        if(i==arr.size()){
            return;
        }

        solve(i+1, arr, temp, target);

        temp.push_back(arr[i]);
        solve(i, arr, temp, target-arr[i]);

        //backtracking step
        temp.pop_back();
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        ans.clear();
        vector<int> temp; 
        solve(0, candidates, temp, target); 
        return ans; 
    }
};
