/*
Given the root of a binary tree, return its maximum depth.

A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
*/

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
class Solution {
public:
    int maxDepth(TreeNode* root) {
        //Termination condition
        if(!root)return  0;
        //Computing the maximum height of left sub tree
        int left=maxDepth(root->left);

        //Computing the maximum height of right sub tree
        int right=maxDepth(root->right);

        //Final answer would be 1+max(left,right) 
        //1 is added to count the root node
       return max(left,right)+1;

    }
};
