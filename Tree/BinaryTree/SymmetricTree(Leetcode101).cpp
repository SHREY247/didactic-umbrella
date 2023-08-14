/*
Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).


Complexity
Time complexity:
O(N)

Space complexity:
O(H)

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

class Solution {
public:
    //Function to check if tree with root r1 is mirror image of tree with roor r2
    bool isMirror(TreeNode * r1, TreeNode * r2){
        //If both r1 and r2 are NULL
        if(!r1 && !r2){
            return true;
        }

        //If one root is NULL and other is not, they can't be mirror images
        if(!r1 || !r2){
            return false;
        }

        //Return true only if r1 and r2 have same value and the left sub tree of r1 is mirror image of right subtree of r2 and vice versa
        return (r1->val == r2->val) && isMirror(r1->left, r2->right) && isMirror(r1->right, r2->left);
    }

    bool isSymmetric(TreeNode* root) {
        //If root is NULL, it is symmetric
        if(!root) return true;

        //If only root exists, then also symmetric
        if(!root->left && !root->right) return true;

        //If left and right sub trees of root are mirror images of each other, then tree is symmetric 
        return isMirror(root->left, root->right);                
    }
};
