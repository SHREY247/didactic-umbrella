/*Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

Note: A leaf is a node with no children.

Input: root = [3,9,20,null,null,15,7]
Output: 2

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
    int minDepth(TreeNode* root) {
        //If root is NULL, return 0
        if(!root){
            return 0;
        }

        //If leaf node, return height as 1
        if(!root->left && !root->right) {
            return 1;
        }

        //Initialize ans as maximum possible value
        int ans=INT_MAX;

        //If root->left exists, calculate minDepth of left sub tree
        if(root->left){
            ans=min(minDepth(root->left),ans);
        }
        
        //If root->right exists, calculate minDepth of right sub tree
        if(root->right){
            ans=min(minDepth(root->right),ans);
        }
        
        //1 added to add contribution of root node
        return ans+1;
    }
};
 
