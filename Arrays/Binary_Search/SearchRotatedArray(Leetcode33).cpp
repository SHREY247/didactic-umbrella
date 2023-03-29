/*There is an integer array nums sorted in ascending order (with distinct values).

Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();

        int s=0;
        int e = n-1;

        while(s<=e){
            int mid=(s+e)/2;

            if(nums[mid]==target){
                return mid;
            }

            //2 cases, mid lies in part 1 or 2

            //mid lies in the left side 
            if(nums[s]<=nums[mid]){
                if(target>=nums[s] && target<=nums[mid]){
                    e=mid-1;
                }
                else{
                    s=mid+1;
                }

            }
            //mid lies in the right side
            else{
                if(target>=nums[mid] && target<=nums[e]){
                        s=mid+1;
                }
                else{
                    e=mid-1;
                }
            }
        }
        return -1;       
    }
};
