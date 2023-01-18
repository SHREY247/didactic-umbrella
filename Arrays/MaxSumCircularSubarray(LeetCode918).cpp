/*Given a circular integer array nums of length n, return the maximum possible sum of a non-empty subarray of nums.
A circular array means the end of the array connects to the beginning of the array.
Formally, the next element of nums[i] is nums[(i + 1) % n] and the previous element of nums[i] is nums[(i - 1 + n) % n].
A subarray may only include each element of the fixed buffer nums at most once. Formally, for a subarray nums[i], nums[i + 1], ..., nums[j],
there does not exist i <= k1, k2 <= j with k1 % n == k2 % n.*/


class Solution {
 public:
  int maxSubarraySumCircular(vector<int>& A) {
    int totalSum = 0;
    int currMaxSum = 0;
    int currMinSum = 0;
    int maxSum = INT_MIN;
    int minSum = INT_MAX;

    for (int a : A) {
      totalSum += a;
      currMaxSum = max(currMaxSum + a, a);
      currMinSum = min(currMinSum + a, a);
      maxSum = max(maxSum, currMaxSum);
      minSum = min(minSum, currMinSum);
    }

    return maxSum < 0 ? maxSum : max(maxSum, totalSum - minSum);  //IF maxSum<=0 then it doesn't come from circular subarray but from straight subarray
  }
};
