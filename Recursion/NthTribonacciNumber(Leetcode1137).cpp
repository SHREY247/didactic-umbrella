/*The Tribonacci sequence Tn is defined as follows: 
T0 = 0, T1 = 1, T2 = 1, and Tn+3 = Tn + Tn+1 + Tn+2 for n >= 0.
Given n, return the value of Tn.*/

class Solution {
public:
    int solve(int n,vector<int>&nums){
        if(nums[n]!=-1){
            return nums[n];
        }
        return nums[n]=solve(n-1,nums) + solve(n-2,nums) + solve(n-3,nums);
    }
    int tribonacci(int n) {
        vector<int>nums(38,-1);
        nums[0]=0,nums[1]=1,nums[2]=1;
        return solve(n,nums);
         }
};

 
