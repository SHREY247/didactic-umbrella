//Maximum subarray sum 
class Solution {
public:
    int maxSubArray(vector<int> &nums) {
        int globalMaxSum = INT_MIN, currMaxSum =0;
        for (int ind = 0; ind < nums.size(); ind++) {
            currMaxSum = max(currMaxSum + nums[ind], nums[ind]);
            globalMaxSum = max(globalMaxSum, currMaxSum);
        }
        return globalMaxSum;
    }
};
