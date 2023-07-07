//Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

class Solution {   
private :
    void permute(vector<int> &nums, vector<vector<int>> &ans, vector<int> &temp, int index){
        //Base case: When index becomes equal to size of nums push_back temp into ans
        if(index == nums.size()){
            ans.push_back(temp);
            return;
        }

        //Swap for different permutations
        //Example For 1st iteration
        //swap 0th element with 0th element and then print all permutations from index+1 
        //Then unswap so that original array remains unchanged
        //Now, swap 0th element with 1st element and print permutations and similarly the loop goes on uptil i=temp.size() - 1
        for(int i=index; i<temp.size(); i++){
             swap(temp[index] , temp[i]);
             permute(nums, ans, temp, index+1);
        //Swap back so that original array remains unchanged  
             swap(temp[index] , temp[i]);
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp = nums;
        permute(nums, ans, temp, 0);
        return ans;
    }
};
