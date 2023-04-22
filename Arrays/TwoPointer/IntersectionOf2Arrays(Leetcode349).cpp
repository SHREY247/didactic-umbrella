/*Given two integer arrays nums1 and nums2, return an array of their intersection.
Each element in the result must be unique and you may return the result in any order.*/

 
/*The approach of this solution is to sort both arrays first.
Then, use two pointers, one for each array, to iterate through the arrays and compare the elements. 
At each iteration, compare the elements at the current positions of both pointers.
If the elements are equal, add the element to the output vector and advance both pointers. 
If the element in nums1 is greater than the element in nums2, advance the pointer for nums2.
If the element in nums1 is less than the element in nums2, advance the pointer for nums1. */

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        int n=nums1.size();
        int m=nums2.size();
        int i=0;
        int j=0;
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        while(i<n && j<m){
            //this will help to remove the duplicate entries
            if(i > 0 && nums1[i]==nums1[i-1]){
                i++;
                continue;
            }
            //helps to push the elements in the array
            if(nums1[i]==nums2[j]){
                ans.push_back(nums1[i]);
                i++;
                j++;
            }
            //increments if element of the other array is smaller
            else if(nums1[i]>nums2[j]){
                j++;
            }
            else{
                i++;
            }
        }
        return ans;
    }
};

