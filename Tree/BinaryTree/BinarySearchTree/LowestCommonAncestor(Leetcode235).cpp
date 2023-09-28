/*
Given a binary search tree (BST), find the lowest common ancestor (LCA) node of two given nodes in the BST.
According to the definition of LCA on Wikipedia: 
“The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants 
(where we allow a node to be a descendant of itself).”

Intuition
We need to find out the node where p and q got split,i.e., p is on one side of the node and q is on the other side of the node

Approach
1: Start at the root of the BST.
2: Compare the values of p and q with the value of the current node.
3: If both p and q are less than the current node's value, it means that both p and q are in the left subtree of the current node. Therefore, recursively call the function on the left subtree.
4: If both p and q are greater than the current node's value, it means that both p and q are in the right subtree of the current node. Therefore, recursively call the function on the right subtree.
5: If one value is less than the current node's value and the other is greater, it means that p and q are on different sides of the current node, so the current node is the LCA.

Complexity
Time complexity:
O(H)

Space complexity:
O(H)
*/ 

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL) return NULL;
        int curr=root->val;
        if(p->val < curr && q->val<curr) 
        {
            return lowestCommonAncestor(root->left,p,q);
        }

        if(p->val > curr && q->val > curr){
            return lowestCommonAncestor(root->right,p,q);
        }


        return root;           
    }
};
