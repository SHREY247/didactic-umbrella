/*You are given an array of integers nums and an integer target.

Return the number of non-empty subsequences of nums such that the sum of the minimum
and maximum element on it is less or equal to target. Since the answer may be too large, return it modulo 109 + 7.

Example:
Input: nums = [3,5,6,7], target = 9
Output: 4
Explanation: There are 4 subsequences that satisfy the condition.
[3] -> Min value + max value <= target (3 + 3 <= 9)
[3,5] -> (3 + 5 <= 9)
[3,5,6] -> (3 + 6 <= 9)
[3,6] -> (3 + 6 <= 9)

Approach:
1: Firstly, sort the given array
2: 2 pointers l and r are to be used, l=0 and r=n-1 (n being the size of array)
3: Check for sum of min and max element, if it is greater than target decrement the r pointer, indicating that last element is out of the consideration for subsequences
4: If sum of first and last element is less than or equal to target, then we need to consider all the subsequences with those elements and add that number to final answer. Also increment the l pointer to check next subsequences.
5: Total number of subsequences possible: 2^N (N=r-l, for that particular iteration).

Complexity
Time: O(N.LogN)
Space: O(N)

*/

class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {

        sort(nums.begin(),nums.end());
        int ans=0;
        int mod=1e9+7;
        vector<int>pow(nums.size(),1);
        int l=0,r=nums.size()-1;
        for(int i=1;i<nums.size();i++)
        {
            pow[i]=(pow[i-1]*2)%mod;
        }
        while(l<=r)
        {
            if(nums[l]+nums[r]>target)
                r--;
            else
            {
                ans=(ans+pow[r-l])%mod;
                l++;

            }
        }
        return ans;
    }
};
