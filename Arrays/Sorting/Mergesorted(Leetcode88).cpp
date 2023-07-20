/*  You are given two integer arrays nums1 and nums2, sorted in non-decreasing order,
and two integers m and n, representing the number of elements in nums1 and nums2 respectively.
Merge nums1 and nums2 into a single array sorted in non-decreasing order.
The final sorted array should not be returned by the function, but instead be stored inside the array nums1. 
To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged,
and the last n elements are set to 0 and should be ignored. nums2 has a length of n.*/

//Code
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        //Filling  nums1 vector from the end
        int i=m-1,j=n-1,k=m+n-1;
        while(i>=0&&j>=0)
        {   
            //If last element of nums1 is greater than last element of nums2, then the larger one would come at the end
            //nums1[i] is filled at the last slot and we update the values of i and k and the loop goes on...
            if(nums1[i]>nums2[j])
            {
                nums1[k]=nums1[i];
                i--;
                k--;
            }

            //If last element of nums2 is greater
            else
            {
                nums1[k]=nums2[j];
                j--;
                k--;
            }
        }
        //Case when some elements are left in nums1
        while(i>=0)
            nums1[k--]=nums1[i--];

        //Case when some elements are left in nums2    
        while(j>=0)
            nums1[k--]=nums2[j--];
    }
};
 
