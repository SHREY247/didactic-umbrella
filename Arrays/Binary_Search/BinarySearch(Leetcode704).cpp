/*Given an array of integers nums which is sorted in ascending order, and an integer target, write a function to search target in nums.
If target exists, then return its index. Otherwise, return -1.

You must write an algorithm with O(log n) runtime complexity.*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int s=0,e=n-1;
        while(s<=e){
        //To prevent overflow
        int mid=s+(e-s)/2;
        if(nums[mid]==target){
            return mid;
        }
        else if(nums[mid]>target){
            e=mid-1;
        }
        else{
            s=mid+1;
        } 
        
        }
        return -1;
       }
};
