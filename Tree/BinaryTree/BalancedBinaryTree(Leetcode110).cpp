/*
Given a binary tree, determine if it is 
height-balanced
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


 // Height Balanced binary tree is the one in which every node has height difference of atmost 1 unit between its left and right sub tree
class Solution {
public:
    //Function which checks whether tree rooted at root is height balanced and returns boolean as first value and height of the tree as second value
    pair<bool, int> CheckBalanced(TreeNode * root){
        //If root points to NULL, return {true,0} because such a tree is balanced and has height 0
        if(!root){
            return {true,0};
        }

        //Recursive call on root->left
        pair<bool, int> lst=CheckBalanced(root->left);

        //Recursive call on root0>right
        pair<bool,int> rst = CheckBalanced(root->right);

        //Tree would be balanced if both left and right sub trees are balanced and also check for the difference between heights of both left and right sub tree, that should atmost be 1
        bool f= lst.first && rst.first && abs(lst.second - rst.second)<=1;
        int h = 1+max(lst.second,rst.second);
        return {f,h};
    }
    bool isBalanced(TreeNode* root) {
        pair<bool,int> ans=CheckBalanced(root);
        return ans.first;                
    }
};
