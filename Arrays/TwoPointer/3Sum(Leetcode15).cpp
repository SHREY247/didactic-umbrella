/*
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
Notice that the solution set must not contain duplicate triplets.
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        vector<vector<int>> ans;

        //Firstly, sort the given vector
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<nums.size();i++){
            //If we keep on getting same nums[i], just continue as we need to consider only unique triplets
            if(i>0 && nums[i]==nums[i-1]) continue;
            else{
                //Fixing first element as nums[i], the sum of next 2 elements must be equal to -nums[i]
                int rem=(-1)*nums[i];
                //Apply 2 pointer approach on the remaining vector starting from i+1 to n-1 and search for such elements whose sum is -nums[i]
                int s=i+1 , e=nums.size()-1;
                //Binary search
                while(s<e){
                    if(nums[s]+nums[e]<rem) s++;
                    else if(nums[s]+nums[e]>rem) e--;
                    //Push all the three numbers into the ans vector
                    else{
                        vector<int> vec;
                        vec.push_back(nums[i]);
                        vec.push_back(nums[s]);
                        vec.push_back(nums[e]);
                        ans.push_back(vec);
                        
                        //If both s and e point to same element, break as we can't get a unique pair now
                        if(nums[s]==nums[e]) break;
                        else{
                            int x=nums[s] , y=nums[e];
                            //To ensure uniqueness, keep on incrementing s till you find same value as nums[s] that has already been considered
                            while(nums[s]==x) s++;
                            //Similarly, keep on decrementing e till the value of nums[e] is same as already the one already considered
                            while(nums[e]==y) e--;
                        }
                    }
                }
            }
        }
        return ans;
    }
};
