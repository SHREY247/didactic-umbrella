/*
The set [1, 2, 3, ..., n] contains a total of n! unique permutations.
By listing and labeling all of the permutations in order, we get the following sequence for n = 3:

"123"
"132"
"213"
"231"
"312"
"321"

Given n and k, return the kth permutation sequence.
Example:
Input: n = 3, k = 3
Output: "213"
*/

    //Example in case of 1 2 3 4 
    //First positon can be filled in 4 ways
    //After fixing the first position, The next 3 positions can be filled in 3! ways
    //Therefore, each number would have 6 choices
    //First 6 permutations would start with: 1
    //Next 6 with 2, next 6 with 3 and the last 6 with 4
    //Kth permutation means (K-1)th as we follow 0 based indexing
    //K=9, K-1=8 
    //8th permutation would lie in (8/6) = 1st block
    //And our answer will be 8%6, i.e., 2 which means 2nd sequence from 1st block
    //K=K%6, so K=2
    //2 occupies the first place in our answer
    //The next position would be occcupied by any of {1,3,4}
    //Again fixing 1 block, next 2 positions can be filled in 2 ways
    //First 2 sequences would start with 1
    //next 2 with 3 and next 2 with 4
    //K=2 so our 2nd permutation will lie in K/2 i.e. 2/2, i.e. 1st block
    //K=K%2 = 0 which means 0th sequence from 1st block
    //1st block starts with 3                                                     3 __ __ __
    //3 occupies 2nd position
    //Elements left: {1,4} K=0
    //1 block starts with 1
    //2nd block starts with 4                                                     3 4 __ __
    //K=0 so (0/1)th block
    //K%1 = 0 so 0th sequence of 0th block
    // start with 1                                                               3  4  1   __
    //Only 2 left so place 2                                                      3  4  1   2

  class Solution {
public:
    string getPermutation(int n, int k) {
        int fact=1;
        vector<int> nums;
        for(int i=1;i<n;i++){
            fact=fact*i;
            nums.push_back(i);
        }
        nums.push_back(n);
        k=k-1;
        string ans="";
        while(true){
            ans=ans+to_string(nums[k/fact]);
            nums.erase(nums.begin()+k/fact);
            if(nums.size()==0){
                break;
            }
            k=k%fact;
            fact=fact/nums.size();
        }
        return ans;
    }
};



 
