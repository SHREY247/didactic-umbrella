//Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

class Solution {   
private :
    void permute(vector<int> &nums, vector<vector<int>> &ans, vector<int> &temp, int index){
        if(index == nums.size()){
            ans.push_back(temp);
            return;
        }

        //Swap for different permutations
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
