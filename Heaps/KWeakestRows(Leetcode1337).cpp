/*You are given an m x n binary matrix mat of 1's (representing soldiers) and 0's (representing civilians). The soldiers are positioned in front of the civilians. That is, all the 1's will appear to the left of all the 0's in each row.

A row i is weaker than a row j if one of the following is true:

The number of soldiers in row i is less than the number of soldiers in row j.
Both rows have the same number of soldiers and i < j.
Return the indices of the k weakest rows in the matrix ordered from weakest to strongest.

Example:
Input: mat = 
[[1,1,0,0,0],
 [1,1,1,1,0],
 [1,0,0,0,0],
 [1,1,0,0,0],
 [1,1,1,1,1]], 
k = 3
Output: [2,0,3]
Explanation: 
The number of soldiers in each row is: 
- Row 0: 2 
- Row 1: 4 
- Row 2: 1 
- Row 3: 2 
- Row 4: 5 
The rows ordered from weakest to strongest are [2,0,3,1,4].*/


/*Approach:
Count the no of ones in each row and then push them into the priority queue and at the same time
also check the size of the priority queue if the size of the priority queue exceeds the k then insert
element by checking into the priority queue*/

class Solution {
public:

    int findOnes(vector<vector<int>>&mat, int row){
        int col = mat[0].size();
        int ans = 0;
        for(int j = 0; j<col; j++){
            if(mat[row][j] == 1){
                ans+=1;
            }else{
                break;
            }
        }
        return ans;
    }


    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int row = mat.size();
        int col = mat[0].size();

        priority_queue<pair<int,int>>pq;

        for(int i = 0; i<row; i++){
            int oneCount = findOnes(mat, i);
            if(pq.size() < k){
                pq.push({oneCount, i});
            }
            
            else if(pq.size() >= k && oneCount < pq.top().first){
                pq.pop();
                pq.push({oneCount, i});
            }
        }

        vector<int>ans;
        while(!pq.empty()){
            pair<int,int>p = pq.top();
            pq.pop();
            ans.push_back(p.second);
        }
        reverse(ans.begin(), ans.end());

        return ans;
    }
};



 
