/* non-empty array of integers nums, every element appears twice except for one. Find that single one.

You must implement a solution with a linear runtime complexity and use only constant extra space.*/

//Whenever we need to find some missing number we must use XOR
//Only that element would remain in answer whose occurence was 1 time because XOR of 2 same numbers will result in 0
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans=0;
        for(auto x:nums)
        ans^=x;
        return ans;
    }
};
