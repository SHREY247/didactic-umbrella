/*
Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

 

Example 1:

Input: nums = [3,2,3]
Output: 3
Example 2:

Input: nums = [2,2,1,1,1,2,2]
Output: 2

Intuition
This code is an implementation of the "Boyer-Moore Voting Algorithm"
The key insight behind this algorithm is that if we cancel out each occurrence of an element with all the other elements that are different from it, the majority element (if it exists) will remain.

Approach
1: Initialize two variables: candidate and count. candidate represents the current majority element candidate, and count represents the count of occurrences of candidate.
2:Iterate through the array nums:
If count is 0, it means we've encountered an equal number of candidate and non-candidate elements so far. In this case, we set candidate to the current element.
3: If the current element is the same as candidate, we increment count since it's a vote in favor of the current candidate. Otherwise, we decrement count since it's a vote against the current candidate.
4:The final value of candidate will be the majority element.

Complexity
Time complexity:
O(N)

Space complexity:
O(1)

Code
*/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int candidate = 0;
        
        for (int num : nums) {
            if (count == 0) {
                candidate = num;
            }
            
            if (num == candidate) {
                count++;
            } else {
                count--;
            }
        }
        
        return candidate;
    }
};
