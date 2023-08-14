/*
Given the root of a binary tree, return the sum of all left leaves.
A leaf is a node with no children. A left leaf is a leaf that is the left child of another node.
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
    int ans =0;
    void Sum(TreeNode* root){
        //If root itself is NULL, just return
         if(root==NULL ) return;
        
        //Check if root_>left exists
        if(root->left!=NULL){
            //Check whether it is leaf node
            if(root->left->left ==NULL && root->left->right==NULL){
                //Add val to ans
                ans = ans+root->left->val;
            }
        }

        //Recursive call on root->left
        Sum(root->left);

        //Recursive call on root->right
        Sum(root->right);
    }

    int sumOfLeftLeaves(TreeNode* root) {
       Sum(root);
       return ans;
    }
};
