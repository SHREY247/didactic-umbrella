/*Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
Notice that the solution set must not contain duplicate triplets.
Example 1:

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation: 
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].
Notice that the order of the output and the order of the triplets does not matter.
 Intuition
First sort the input array. Then, use a combination of two pointers approach within a loop to efficiently find the triplets. The outer loop (i) selects a fixed element and the inner loop (j and k) uses two pointers to find the remaining two elements such that their sum equals zero.

Approach
1: Sort the nums vector
2: Using outer loop, we fix the first element of the triplet
3: Also, we check for duplicates for the first element and skip those if they exist
4: Two Pointer Technique (j and k): The inner loop uses two pointers (j and k) which are initially set to the elements just after i and at the end of the array respectively.
5: While Loop (j < k): This loop continues as long as j is less than k, Calculate sum of the three elements (nums[i] + nums[j] + nums[k]).
6:Sum Comparison:
If the sum is zero, it means we've found a triplet. It's added to the output vector.
8: Duplicate Checks (j and k): After finding a triplet, there are checks to skip duplicates to avoid duplicate triplets in the output.
9: If the sum is less than zero, j is incremented to consider larger elements.
10: If the sum is greater than zero, k is decremented to consider smaller elements.

Time Complexity
O(NlogN) (Sorting) + O(NN) (2 pointer technique applied)
Overall: O(N^2)

Space Complexity
O(K), K is number of valid triplets present in output vector

Code
*/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> output;
        int n = nums.size();
        for (int i = 0; i < n - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue; // Skip duplicates
            int j = i + 1;
            int k = n - 1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == 0) {
                    output.push_back({nums[i], nums[j], nums[k]});
                    while (j < k && nums[j] == nums[j + 1]) j++; // Skip duplicates
                    while (j < k && nums[k] == nums[k - 1]) k--; // Skip duplicates
                    j++;
                    k--;
                } else if (sum < 0) {
                    j++;
                } else {
                    k--;
                }
            }
        }
        return output;
    }
};
