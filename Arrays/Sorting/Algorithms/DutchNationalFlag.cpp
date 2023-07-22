/*
The Dutch National Flag algorithm, also known as 3-way partitioning, is an algorithm for sorting an array containing three distinct values. 
The algorithm was designed to solve the problem of sorting an array containing only 0s, 1s, and 2s.
The algorithm works by maintaining three pointers: low, mid, and high.
The low pointer points to the beginning of the array, the high pointer points to the end of the array, and the mid pointer starts at the beginning of the array and moves through it.
The idea behind the algorithm is to keep all the 0s before the low pointer, all the 2s after the high pointer, and all the 1s between the low and high pointers. 
The algorithm moves the mid pointer through the array, comparing the value at each position with 1. If the value is 0, 
the element is swapped with the element at the low pointer, and the low and mid pointers are incremented. If the value is 2,
the element is swapped with the element at the high pointer, and the high pointer is decremented. If the value is 1, the mid pointer is simply incremented. 
Terminate when mid becomes greater than high, that is sorting has been done
*/ 

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0, mid = 0, high = nums.size()-1;
        while(mid <= high){
            if(nums[mid] == 0){
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            }
            else if(nums[mid] == 1){
                mid++;
            }
            else{
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};
