//Given an integer array nums and an integer k, return the number of non-empty subarrays that have a sum divisible by k.

/*For any subarray [i..j] whose sum is divisible by k, we can easily see that prefixSum[j] - prefixSum[i-1] = 0.
Thus if there are any repetitions in our prefixSum%k array, that represents a required subarray.
So if we have the count of every possible value of prefixSum%k,
we can determine if there are any subarray that end at the current index and the sum is divisible by k.*/

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> sums(k, 0);
        sums[0]++;                                //Initially, cumulative sum is 0 and therefore frequency of 0 is 1
        int cnt = 0;
        int currSum = 0;
        for(int i = 0; i<n; i++) {
            currSum = (currSum + nums[i]%k + k)%k;
            cnt += sums[currSum];
            sums[currSum]++;
        }
        return cnt;
    }
};
