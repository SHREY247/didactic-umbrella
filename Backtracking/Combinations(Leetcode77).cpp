/*Given two integers n and k, return all possible combinations of k numbers chosen from the range [1, n].
You may return the answer in any order.*/

/*Example:
Input: n = 4, k = 2
Output: [[1,2],[1,3],[1,4],[2,3],[2,4],[3,4]]
Explanation: There are 4 choose 2 = 6 total combinations.
Note that combinations are unordered, i.e., [1,2] and [2,1] are considered to be the same combination.
 */

class Solution {
public:
    vector<vector<int>> ans;
    
    void helper(int idx, int k,vector<int>&current,int n)
    {   
        //Base case: if size of current vector becomes equal to k, push current into ans and return
        if(current.size()==k)    
        {
            ans.push_back(current);
            return;
        }
        

        for(int i=idx;i<n+1;i++)
        {   
            current.push_back(i);  //consider the current element i
            helper(i+1,k,current,n); //generate combinations
            current.pop_back(); //Pop the current element and proceed with the next one
        }
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<int>current;
        //Start with idx=1 
        helper(1,k,current,n);
        return ans; //return answer
    }
};
