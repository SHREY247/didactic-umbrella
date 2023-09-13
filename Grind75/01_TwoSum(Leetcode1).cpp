/*
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
You can return the answer in any order.
*/

/*We store the numbers and their actual indices in a vector of pairs. 
Then we sort the vector on the basis of numbers. Now, we maintain 2 pointers, first at the starting and second one at the last of the vector. 
Now, check if sum equals target, return the actual indices, else if sum less than target, increase the left pointer, else if target is lesser than sum, 
decrement the right pointer.

Time Complexity: O(NlogN)
Space Complexity: O(N)
*/
    
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++){
            v.push_back({nums[i],i});
        }

        sort(v.begin(),v.end());
        int l=0,r=n-1;
        while(l<r){
            int sum=v[l].first + v[r].first;
            if(sum==target){
                return {v[l].second, v[r].second};
            }

            else if(sum<target){
                l++;
            }   

            else{
                r--;
            }        
        }
        return {};
    }
};
