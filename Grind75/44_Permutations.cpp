/*
Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.
Example 1:
Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

  Intuition
Using backtracking, we generate all possible permutations of a given set of numbers.

Approach
1: Backtracking with Recursion: The permute function uses recursion and backtracking to generate permutations.
2: Element Swapping: It explores permutations by swapping elements at different positions and backtracking to explore other options.
3: Base Case: When the current index reaches the size of the input array, a new permutation is generated and added to the answer vector.
4: Restoring Original State: Swapping elements back to their original positions after exploring permutations at a specific index ensures the original array remains unchanged.

Time Complexity
O(N!*N), O(N) time to copy elememts into answer vector for each permutation and in total there are N! permutations

Space Complexity
O(N! * N), (because ans would contain N! permutations and each would contain N elements each)
*/


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
