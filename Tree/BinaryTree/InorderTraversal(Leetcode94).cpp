/*
Given the root of a binary tree, return the inorder traversal of its nodes' values.
  */
/*Intuition
Inorder Traversal Order: Left Sub Tree, Root, Right Sub Tree
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


//Iterative approach
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

 //Iterative method using stack
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> v;
        stack<TreeNode*> stk;
        //Keep on pushing root into stack  and update it to root->left until root becomes NULL

        while(root){
            stk.push(root);
            root = root->left;
        }

        //Value of top of the stack is inserted into the vector because its left sub tree is null
        //Then do inorder traversal for right sub tree of this node
        while(!stk.empty()){
            v.push_back(stk.top()->val);
            TreeNode* temp = stk.top()->right;
            stk.pop();
            //Inorder traversal of right sub tree
            while(temp){
                stk.push(temp);
                temp = temp->left;
            }
        }
        return v;
 
    }
};



//Recursive approach
class Solution {
public:
    vector<int> ans;
    vector<int> inorderTraversal(TreeNode* root) {
        if(!root) return {};
        //Recursive call on root->left
        inorderTraversal(root->left);

        //Push the root ->val 
        ans.push_back(root->val);

        //Recursive call on root->right
        inorderTraversal(root->right);
        return ans;      
    }
};
