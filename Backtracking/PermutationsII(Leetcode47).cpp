/*Given a collection of numbers, nums, that might contain duplicates, return all possible unique permutations in any order.

Example:
Input: nums = [1,1,2]
Output:
[[1,1,2],
 [1,2,1],
 [2,1,1]]
*/

class Solution {
public:
    //Swap function
    void swap(vector<int>& nums, int i, int j){
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
        return;
    }
    
    void permute(vector<int>& nums, int i, vector<vector<int>> &ans){
        //-10 <= nums[i] <= 10 constraint
        //-10 -9 -8 ....... 0 1 2 3 4 ..... type of number line
        //1 is at 11th index on this numberr line
        vector<int> freq(21,0);
        
        //Base case
        if(i == nums.size()-1){
            ans.push_back(nums);
            return;
        }


        for(int j =i; j<nums.size(); j++){
            if(freq[nums[j]+10]==0){
                //swap to generate different permutations
                swap(nums,i,j);
                permute(nums,i+1, ans);
                //unswap: Backtrack
                swap(nums,i,j);
            }
            //Update the frequency so that we don't generate same permutayions again and again
            freq[nums[j]+10]++;
        }
        
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        int i =0;
        permute(nums, i, ans);
        return ans;
    }
};
