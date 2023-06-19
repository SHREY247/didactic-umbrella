/*A swap is defined as taking two distinct positions in an array and swapping the values in them.
A circular array is defined as an array where we consider the first element and the last element to be adjacent.
Given a binary circular array nums, return the minimum number of swaps required to group all 1's present in the array together at any location.*/
/*Example 1:

Input: nums = [0,1,0,1,1,0,0]
Output: 1
Explanation: Here are a few of the ways to group all the 1's together:
[0,0,1,1,1,0,0] using 1 swap.
[0,1,1,1,0,0,0] using 1 swap.
[1,1,0,0,0,0,1] using 2 swaps (using the circular property of the array).
There is no way to group all 1's together with 0 swaps.
Thus, the minimum number of swaps required is 1.*/



class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        // count the no. of ones in nums
        int countone = 0;
        for(int i = 0; i < n; i++)
        {
            if(nums[i])
            {
                countone++;
            }
        }

        // if count of 1 is zero then return 0

        if(countone == 0)
        {
            return 0;
        }

        // make arr by concatenating nums to itself, for handling the case of circular array

        vector<int> arr = nums;

        for(int i = 0; i < n; i++)
        {
            arr.push_back(nums[i]);
        }

        // now find the maximum no. of ones in countone sized subarray

        int maxi = 0;

        int count = 0;

        for(int i = 0; i < arr.size(); i++)
        {
            if(i < countone)
            {
                if(arr[i])
                {
                    count++;
                }
            }
            else
            {
                maxi = max(maxi, count);

                if(arr[i - countone])
                {
                    count--;
                }

                if(arr[i])
                {
                    count++;
                }
            }
        }

        maxi = max(maxi, count);

        // countone - maxi will be required no. of swaps

        return countone - maxi;
    }
};


 
