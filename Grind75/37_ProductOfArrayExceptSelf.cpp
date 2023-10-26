/*
Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].
The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
You must write an algorithm that runs in O(n) time and without using the division operation.
Example 1:
Input: nums = [1,2,3,4]
Output: [24,12,8,6]


  Intuition
We use two passes through the input array nums. In the first pass, we calculate the product of all elements to the left of each element and store it in the ans vector. In the second pass, we calculate the product of all elements to the right of each element and update the corresponding element in the ans vector. This way, the ans vector will contain the desired results.

Approach
1: Initialize a vector ans of the same size as nums to store the results.
2: Initialize a variable prod to keep track of the product of elements to the left of nums[i]. Start it at 1.
3: In the first pass, iterate through nums from left to right. For each element nums[i], set ans[i] to prod (which is the product of all elements to the left of nums[i]) and update prod by multiplying it with nums[i].
4: Initialize another variable revProd to keep track of the product of elements to the right of nums[i]. Start it at 1.
5: In the second pass, iterate through nums from right to left. For each element nums[i], multiply ans[i] (which contains the product of elements to the left of nums[i]) with revProd (which is the product of all elements to the right of nums[i]) and update revProd by multiplying it with nums[i].
6: Finally, return the ans vector containing the desired results.

Complexity
Time complexity:
O(N)

Space complexity:
O(N)

Code
*/
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector <int> ans(n);
        int prod = 1;
        for (int i = 0; i < n; i++) {
            ans[i] = prod;
            prod *= nums[i];
        }
        int revProd = 1;
        for (int i = n - 1; i >= 0; i--) {
            ans[i] *= revProd;
            revProd *= nums[i];
        }
        return ans;   
    }
};
