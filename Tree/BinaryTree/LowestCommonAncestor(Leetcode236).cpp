/*
Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.
According to the definition of LCA on Wikipedia:
“The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as 
descendants (where we allow a node to be a descendant of itself).”
Example 1:
Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
Output: 3
Explanation: The LCA of nodes 5 and 1 is 3.

  Intuition
We utilize a recursive approach to traverse the tree and determine the LCA based on the existence of the given nodes p and q in the left and right subtrees.

Approach
1: The function lowestCommonAncestor takes in the root of the binary tree along with the nodes p and q whose LCA needs to be found.
2: If the root is NULL or matches either of the given nodes p or q, it means that particular node is the ancestor, so the function returns the current root.
3: It recursively checks the left and right subtrees to find the LCA.
4: If both left and right are not NULL, it means that the nodes p and q exist in different subtrees, and the current root is their LCA.
5: If one of left or right is NULL, it means both nodes p and q exist in the same subtree. In this case, the LCA is in the non-NULL subtree.

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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

*/
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL || root == p || root == q){
            return root;
        }

        //Recursive call on left sub tree
        TreeNode* left = lowestCommonAncestor(root -> left,p,q);

        //Recursive call on right sub tree
        TreeNode* right = lowestCommonAncestor(root -> right ,p ,q);
        
        //If left==NULL, it means both the nodes exist in right sub tree
        //So, return lowest common ancestor of right sub tree
        if(left == NULL){
            return right;
        }

        //If right==NULL, it means both the nodes exist in left sub tree
        //So, return lowest common ancestor of left sub tree
        else if(right == NULL){
            return left;
        }

        else{
            //one node exists in left sub tree and another one in the right sub tree so root is Lowest common ancestor
            return root;
        }
    }
};
