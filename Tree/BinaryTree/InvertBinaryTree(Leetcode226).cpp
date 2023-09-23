/*
Given the root of a binary tree, invert the tree, and return its root.
Example:
Input: root = [4,2,7,1,3,6,9]
Output: [4,7,2,9,6,3,1]


Intuition
The function recursively traverses the tree and at each node, swaps its left and right children. This effectively flips the tree along its vertical axis.

Approach
1: Base Case: If the root is NULL, indicating an empty tree or a leaf node, return NULL since there's nothing to invert.

2: Swap Left and Right Children: Swap the root's left and right children. This is the core operation that inverts the tree.

3: Recursive Calls: Recur on the left and right subtrees. This recursively inverts the left and right subtrees of the current node.

4: Return the Root: Finally, return the modified root.

Time Complexity
The time complexity is O(n), where n is the number of nodes in the binary tree. This is because the algorithm visits each node exactly once.

Space Complexity
The space complexity is O(h), where h is the height of the binary tree. This is due to the recursive call stack.
In the worst case, if the tree is completely unbalanced (resembling a linked list), the height h would be n, where n is the number of nodes, 
resulting in a space complexity of O(n). However, in a balanced binary tree, the height would be log(n) and the space complexity would be O(log(n)).
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
    TreeNode* invertTree(TreeNode* root) {
        //Base case
        if(!root){
            return NULL;
        }

        //Swapping the nodes
        TreeNode* tmp = root->left;
        root->left=root->right;
        root->right=tmp;

        //Recursive call on root->left and root->right
        invertTree(root->left);
        invertTree(root->right);



        return root;
    }
};
