/*
There is an integer array nums sorted in ascending order (with distinct values).
Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], 
nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].
Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.
You must write an algorithm with O(log n) runtime complexity.

Example 1:
Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
Intuition
Use modified binary search
The key insight is to determine whether the left or right half of the array is sorted at each step, and based on that information, adjust the search space accordingly

Approach
1: Initialize two pointers, low and high, representing the start and end indices of the array.
2: Use a while loop to iteratively narrow down the search space.
3: Inside the loop, calculate the middle index mid.
4: Check if the element at the middle index is equal to the target. If yes, return the index.
5: Determine if the left or right half of the array is sorted.
a) If the left half is sorted (nums[low] <= nums[mid]), check if the target lies in this sorted half.If yes, adjust the search space to the left half (high = mid - 1), else adjust it to the right half (low = mid + 1).
b) If the right half is sorted (nums[mid] <= nums[high]), check if the target lies in this sorted half.
If yes, adjust the search space to the right half (low = mid + 1), else adjust it to the left half (high = mid - 1).
6: Repeat the process until the search space is exhausted (low > high).

Complexity
Time complexity:
O(log N)

Space complexity:
O(1)
*/
Code
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target) {
                return mid;
            }

            if (nums[low] <= nums[mid]) {
                if (nums[low] <= target && target < nums[mid]) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            } else {
                if (nums[mid] < target && target <= nums[high]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }

        return -1;
    }
};
