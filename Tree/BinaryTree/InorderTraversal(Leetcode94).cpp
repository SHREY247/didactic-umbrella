/*
Given the root of a binary tree, return the inorder traversal of its nodes' values.
  */
/*Intuition
Inorder Traversal Order: Left Sub Tree, Root, Right Sub Tree
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
    vector<int> ans;
    vector<int> inorderTraversal(TreeNode* root) {
        if(!root) return {};
        //Recursive call on root->left
        inorderTraversal(root->left);

        //Push the root ->val 
        ans.push_back(root->val);

        //Recursive call on root->right
        inorderTraversal(root->right);
        return ans;      
    }
};
