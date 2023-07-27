/*
Given an integer array nums where every element appears three times except for one, which appears exactly once. Find the single element and return it.

You must implement a solution with a linear runtime complexity and use only constant extra space.
  */

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        //The total number of set bits should be a multiple of 3 for bit at a particular position
        //If it is not a multiple of 3,  this is due to that extra number which apperared only once so we need to add the contribution of that particular bit to our answer, to find that number
        //In this way, we will calculate the odd one out

        //To check for set bits we will be performing AND of a number with different masks
        //We'll be checking from 31st bit till 0th bit
        long mask = (1L<<31),ans=0;
        for(int i=31;i>=0;i--){
            int count = 0;
            for(int j=0;j<nums.size();j++){
                if(nums[j]&mask)count++;
            }

            if(count%3!=0){
                ans+=mask;
            }

            mask>>=1;
        }
        return ans;
    }
};
