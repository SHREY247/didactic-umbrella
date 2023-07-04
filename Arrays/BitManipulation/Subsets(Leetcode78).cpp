/*Given an integer array nums of unique elements, return all possible 
subsets (the power set).
The solution set must not contain duplicate subsets. Return the solution in any order.

Example:
Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
*/

/*Concept:
Either the number at a particular index is accepted or rejected
At a particular index idx:
Corresponding to yes case, the bit is 1
Corresponding to no case, the bit is 0*/
/*

Approach:
1: Total number of subsets possible are 2^n for a set containing n elements
2: Run a loop from index 0 uptil e where e is 2^n
3: idx is used to point to an index for checking whether to include a particular number (nums[ind]) in the subset or not, initially idx=0
4: Initialize mask to value i and run a while loop uptil (mask>0)
5: To store the current subbset, initialize a tmp vector
5: If last bit of mask is 1, push that particular index in tmp
6: Shift the mask and update idx and similarly check for other indexes
7: Push the final subset obtained into ans
8: Return ans
*/



class Solution
{
public:    
    vector<vector<int>> subsets(vector<int>& nums)
    {
        vector<vector<int>> ans;
        int e = pow(2, nums.size());  // total number of subsets
        for(int i = 0; i < e; i++)
        {
            int mask = i;  // bit mask
            int idx = 0;  // index in nums to determine whether to push a number at a particular index
            vector<int> tmp;  // temp vector to store current subset
            while(mask > 0)
            {
                // if last bit of mask is a 1
                if(mask & 1)
                {
                    // add num to tmp
                    tmp.push_back(nums[idx]);
                }
                // shift mask
                mask >>= 1;
                // update idx
                idx++;
            }
            // add to ans
            ans.push_back(tmp);
        }
        return ans;
    }
};

