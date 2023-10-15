/*
Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).
Example 1:
Input: root = [3,9,20,null,null,15,7]
Output: [[3],[9,20],[15,7]]

  Intuition
Use a queue to store the nodes at each level

Approach
1: Initialize an empty vector output to store the level order traversal result.
2: If the root is nullptr, return an empty output vector.
3: Create a queue q to store the nodes for traversal.
4: Push the root node into the queue q.
5: While the queue is not empty, do the following:
a) Get the size of the queue (n) to know how many nodes are there at the current level.
b) Create a temporary vector temp of size n to hold the values of nodes at the current level.
c) Iterate through the nodes at the current level:

The node in front of the queue is stored in curr
If curr has a left child, enqueue it.
If curr has a right child, enqueue it.
Store curr->val in temp.
Push the temp vector (values of the current level) into the output vector.
6: Once the traversal is complete, return the output vector.

Complexity
Time complexity:
O(N)

Space complexity:
O(N)

Code
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
*/
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        vector<vector<int>> output;
        if(root==nullptr){
            return output;
        }
        
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
           
            int n=q.size();
            vector<int> temp(n,0);
            for(int i=0;i<n;i++){
                 auto curr=q.front();
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
                temp[i]=curr->val;
                q.pop();
            }
            output.push_back(temp);
        }

        return output;
    }
};
