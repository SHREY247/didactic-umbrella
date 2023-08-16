/*
Given the root of a binary tree, return all root-to-leaf paths in any order.

A leaf is a node with no children.

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
    void solve(TreeNode * root, vector<string>&ans, string s)
    {   
        //Return, if root points to NULL
        if(!root)return;

        //If a leaf node, add contents to the string s and push s into ans
        if(!root->left && !root->right)
        {
            s += to_string(root->val);
            ans.push_back(s);
        }

        //If not a leaf node then firstly push the node into s
        s += to_string(root->val);
        //Call solve on root->left 
        solve(root->left, ans, s+"->");
         //Call solve on root->right 
        solve(root->right, ans, s+"->");
    }
    vector<string> binaryTreePaths(TreeNode* root) 
    {
        string s = "";
        vector<string>ans;
        solve(root, ans, s);    
        return ans;
    }
};
