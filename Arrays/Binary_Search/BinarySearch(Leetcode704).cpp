/*
Given an array of integers nums which is sorted in ascending order, and an integer target, 
write a function to search target in nums. If target exists, then return its index. Otherwise, return -1.
You must write an algorithm with O(log n) runtime complexity.
Approach
1:Initialize two pointers, l and r, to the start and end indices of the vector nums.
2: Enter a loop that continues as long as l is less than or equal to r, ensuring that there is still a valid search range.
3: Calculate the mid-point of the current search range using int mid = (l + r) / 2;.
4:Check if the value at the mid-point, nums[mid], is equal to the target value:
If nums[mid] is equal to the target, return mid as the index of the target.
If nums[mid] is greater than the target, update r to mid - 1 to narrow down the search range to the left half.
If nums[mid] is less than the target, update l to mid + 1 to narrow down the search range to the right half.
5: If the loop completes without finding the target, return -1 to indicate that the target is not present in the array.

Time Complexity
The time complexity of this binary search algorithm is O(log n), where n is the number of elements in the input vector nums. This is because in each iteration, the search range is effectively halved.

Space Complexity
The space complexity is O(1) since the algorithm only uses a constant amount of extra space for variables (l, r, mid).  
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0, r=nums.size()-1;
        while(l<=r){
            int mid=(l+r)/2;
            if(nums[mid]==target){
                return mid;
            }

            else if(nums[mid]>target){
                r=mid-1;
            }

            else{
                l++;
            }
        }
        return -1;        
    }
};
