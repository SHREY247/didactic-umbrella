/*
Given two integer arrays nums1 and nums2, sorted in non-decreasing order, return the minimum integer common to both arrays. If there is no common integer amongst nums1 and nums2, return -1.

Note that an integer is said to be common to nums1 and nums2 if both arrays have at least one occurrence of that integer.

 

Example 1:

Input: nums1 = [1,2,3], nums2 = [2,4]
Output: 2
Explanation: The smallest element common to both arrays is 2, so we return 2.
  Intuition
Use the sorted nature of vectors to efficiently search for the minimum common element, we can use two pointer approach and compare values in both the vectors and find the required element.

Approach
1: The function starts by initializing two pointers a and b to traverse nums1 and nums2 respectively.
2: It checks if there is any possibility for common elements between the two arrays by comparing the last element of nums1 with the first element of nums2, and vice versa. If there's no overlap, it returns -1.
3: It iterates through the arrays using the two pointers:
a) If the elements pointed to by a and b are equal, it returns that common element.
b) If nums1[a] is greater than nums2[b], it increments b.
c) If nums1[a] is less than nums2[b], it increments a.
4: If no common element is found during traversal, it returns -1.

Complexity
Time complexity:
O(p+q)
Because The algorithm traverses through both vectors at most once, incrementing the pointers a and b until either a reaches the end of nums1 or b reaches the end of nums2.

Space complexity:
O(1)
The function only uses a constant amount of extra space for storing integer variables a, b, p, and q

*/


class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int a=0,b=0;
        int p=nums1.size(), q=nums2.size();
        if((nums1[p-1] < nums2[0]) || nums2[q-1]<nums1[0]){
            return -1;
        }
        while(a<p && b<q){
            if(nums1[a]==nums2[b]){ 
                return nums1[a];
            }
            else if(nums1[a]>nums2[b]){
                b++;
            }
            else{ 
                a++;
            }

        }
        return -1;
        
    }
};


