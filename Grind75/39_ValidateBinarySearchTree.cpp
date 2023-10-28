Given the root of a binary tree, determine if it is a valid binary search tree (BST).
A valid BST is defined as follows:
The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.


  Intuition
At each node, define the range of valid values and recursively check whether all the node values lie within their specified range

Approach
The solve function recursively checks if a given subtree is a valid BST. It takes three parameters: root (the current node), min (the minimum value a node in this subtree can have), and max (the maximum value a node in this subtree can have).

1: If root is NULL, it means we have reached a leaf node or an empty subtree, which is considered a valid BST, so we return true.
2: If the value of the root is less than or equal to min or greater than or equal to max, it violates the BST property, so we return false.
3: Otherwise, we recursively call solve for the left subtree with the updated max (which is now the value of root) and for the right subtree with the updated min (which is now the value of root).

Complexity
Time complexity:
O(N)

Space complexity:
O(H)

Code
*/
class Solution {
public: 
    bool solve(TreeNode* root, long min, long max){
        if(root == NULL)   
            return true;
        
        if(root->val <= min || root->val >= max)  
            return false;
        
        return solve(root->left, min, root->val) && solve(root->right, root->val, max);
    }

    bool isValidBST(TreeNode* root) {
        return solve(root, LONG_MIN, LONG_MAX);
    }
};
