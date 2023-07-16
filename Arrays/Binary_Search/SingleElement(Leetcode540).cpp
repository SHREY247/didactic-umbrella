/*
You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.
Return the single element that appears only once.
Your solution must run in O(log n) time and O(1) space.
Example 1:
Input: nums = [1,1,2,3,3,4,4,8,8]
Output: 2
*/

/*
Approach
We can divide the array into two parts
In one part, the first occurence is at even index and second occurence is at odd index and in the other part when we cross the single element the pattern changes.
*/ 
  

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size(), l=0, r=n-1,mid,ans;
        
        //In case of a single element, return that element itself
        if(n==1){
            return nums[0];
        }
        
        while(l<=r){
            mid = (l+r)/2;
            //If both l and r point to either the first or last element, means that particular element is the ans
            if(mid==0 || mid==n-1){
                ans = nums[mid]; 
                break;               
            }
            
            //If you find a single element 
            if((nums[mid]!=nums[mid-1]) && nums[mid]!=nums[mid+1]){
                ans = nums[mid];
                break;
            }

            else{
                //There is a pattern, in the first part even index is first occurence and odd index is second occurence

                //In case of odd mid as in example 2
                if(mid%2==1){
                    //If nums[mid]==nums[mid+1], answer lies to the left of mid so do r = mid-1 
                    if(nums[mid]==nums[mid+1]){
                        r=mid-1;                                                
                    }    
                    //Otherwise, answer would lie to right of mid do l=mid+1 as in example 2
                    else{
                        l=mid+1;
                    }                
                }

                //When mid is even as in example 1
                else{
                    //Check if mid is first occurence and second occurence exists to the right, then answer lies to the right of mid
                    if(nums[mid]==nums[mid+1]){
                        l=mid+1;                        
                    } 
                    
                    //Otherwise, answer lies to the left of mid as in example 1
                    else{
                        r=mid-1;
                    }                                       
                }
            }
        }
     return ans;     
    }
};
  
