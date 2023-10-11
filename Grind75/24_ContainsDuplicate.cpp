/*
Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.
Example 1:
Input: nums = [1,2,3,1]
Output: true

  Intuition
The code uses an unordered map mp to keep track of the frequency of each element in the nums vector. If the frequency of any element becomes greater than or equal to 1, it means that the element is a duplicate.

Approach
1: Initialize an unordered map mp to store the frequency of elements.
2: Iterate through the nums vector.
For each element num:
Check if num is already in the map.
If it is, return true, indicating a duplicate value
Increment the frequency for that num
3: If the loop completes without finding any duplicates, return false.

Complexity
Time complexity:
O(N)

Space complexity:
O(N)

Code
*/
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (int num : nums) {
            if (mp[num] >= 1)
                return true;
            mp[num]++;
        }
        return false;
    }
};
  
  
