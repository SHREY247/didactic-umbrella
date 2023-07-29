/*
Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.

A subarray is a contiguous non-empty sequence of elements within an array.
*/


class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        //Map would have prefix sum as key and the frequency as value 
        unordered_map <int,int> mp;
        int psum = 0, count = 0;

        //Handling the case of empty array: Sum = 0, frequency = 1
        mp[0]=1;

        for(int i=0;i<nums.size();i++){
            psum+=nums[i];

            //If psum - k exists in the map, add its frequency to the count
            //This is because the subarray between the current index and m[psum-k] would have sum k
            //Explanation: If uptil a particular index prefix sum is psum-k and at another index prefix sum is psum,  then the subarray between these two indexes would definitely have a sum k
            //So, in this way we'll be adding the count of all such subarrays whose sum equals k
            if(mp.find(psum-k)!=mp.end()){
                count+=mp[psum-k];                
            }
            //Update the frequency of prefix sums
            mp[psum]++;
        }
        return count;
    }
};
