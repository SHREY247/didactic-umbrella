/*
Given the root of a binary tree, return the length of the diameter of the tree.

The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

The length of a path between two nodes is represented by the number of edges between them.
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
    //Function which returns pair of int with height and diameter as its first and second value
    pair<int,int> fun(TreeNode* root){
        //If root points to NULL, return {0,0} as such a tree would have 0 height and 0 diameter
        if(!root){
            return {0,0};
        }
        
        //Recursive call on root->left
        pair<int,int> left = fun(root->left);

        //Recursive call on root->right
        pair<int,int> right= fun(root->right);

        //For computing diameter we have 3 possible options:
        //First, Root node is the part of diameter: dia= 1+height(left_tree)+height(right_tree)
        //Second, Diameter is completely the part of left sub tree:dia=left.second
        //Third, diameter is completely part of right sib treedia=right.second
        //Maximum diameter corresponds to maximum of all of these values of diameters
        int dia= max(1+left.first+right.first,max(left.second, right.second));
        
        //height is 1+max(left_height,right_height)
        int height= 1+ max(left.first,right.first);

        return {height,dia};
    }
    int diameterOfBinaryTree(TreeNode* root) {
        pair<int,int> p = fun(root);
        return p.second-1;              
    }
};
