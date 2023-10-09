/*
Given the root of a binary tree, return the length of the diameter of the tree.
The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.
The length of a path between two nodes is represented by the number of edges between them.
Example 1:
Input: root = [1,2,3,4,5]
Output: 3
Explanation: 3 is the length of the path [4,2,1,3] or [5,2,1,3].
Approach
1: The func function is a recursive function that takes a TreeNode* as input and returns a pair of integers. The first integer in the pair represents the height of the subtree rooted at the current node, and the second integer represents the diameter of the subtree rooted at the current node.

2: If the current node is null (i.e., it does not exist), then the function returns a pair (0, 0), indicating that the height and diameter of this subtree are both zero.

3: If the current node exists, the function recursively calls itself on the left and right subtrees.

4: The diameter of the current subtree can be calculated using the formula:
dia = max(1 + left.first + right.first, max(left.second, right.second))

This formula takes the maximum of three values:
The diameter of the subtree that passes through the current node, which is 1 (for the current node) plus the height of the left subtree plus the height of the right subtree.
The maximum diameter of the left subtree.
The maximum diameter of the right subtree.

5: The height of the current subtree is calculated as:
height = 1 + max(left.first, right.first)
This is one more than the maximum height of the left and right subtrees(Taking into account the current node).

6: The function then returns a pair containing the height and diameter of the current subtree.

7: In the diameterOfBinaryTree function, it calls func(root) to get the pair of height and diameter for the entire tree. It then returns p.second - 1 as the final result, since the diameter is defined as the number of edges on the path, and not the number of nodes.

Time Complexity
O(N)

Space Complexity
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
       //pair contains height and diameter
        pair<int,int> func(TreeNode* root){
            if(!root){
                return {0,0};
            }
            pair<int,int> left=func(root->left);
            pair<int,int> right=func(root->right);
            int dia=max(1+left.first+right.first,max(left.second,right.second));
            int height=1+max(left.first,right.first);
            return {height, dia};
        }
    int diameterOfBinaryTree(TreeNode* root) {
        pair<int,int> p=func(root);
        return p.second-1;             
    }
};
