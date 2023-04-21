/*Given the array of integers nums, you will choose two different indices i and j of that array.
Return the maximum value of (nums[i]-1)*(nums[j]-1).*/

/*Approach
Using priority queue we can have top 2 maximum values of nums[i]-1
and we can multiply those 2 values to get our answer*/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
         priority_queue<int> q;
        for(int i=0; i<nums.size(); i++){
            q.push((nums[i]-1));
        }
        
        int p=q.top();
        q.pop();
        return p*q.top();
    }
    
};
