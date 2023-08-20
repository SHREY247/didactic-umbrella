/*
Given the root of a binary tree, return the postorder traversal of its nodes' value
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


//Using the fact that stack is a first in last out structure, we can use 2 stacks 
//In the first stack, we initially push the root
//Using a variable curr, we store root and pop root from first stack and insert it into s2
//This is because we need to print root in the end, so First In Last Out structure, stack is being used

//Now, check if left child exists, then push it into s1
//Similarly, check if right child exists and push it into s1

//Now, stack top would contain right child and we would push it into s2
//Again repeat the process and check whether its left sub tree exists, and right sub tree exists
//The top would again contain the root of right sub tree
//IN this way, finally, we would push the right sub tree into s2
//Lastly, the left sub tree is pushed

//When we pop, the order is Left Sub Tree, Right Sub Tree and root->val

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root==NULL) return ans;

        //Using 2 stacks
        stack<TreeNode*> s1,s2;

        
        s1.push(root);
        while(!s1.empty()){
            TreeNode * curr = s1.top();
            s1.pop();
            //Push curr into s2
            //In example 1, 1 is pushed into s2
            //Since it is pushed at first, it would be popped in the end from s2
            //That is what we want in post order traversal, root must be printed in the end
            s2.push(curr);

            //If left sub tree, exists push it into s1
            //In given example, its null so condition becomes false
            if(curr->left !=NULL){
                s1.push(curr->left);
            }

            //If right sub tree exists push it into s2
            //We would push 2 into s1 
            if(curr->right!=NULL){
                s1.push(curr->right);
            }

            //The loop runs again, curr would contain 2, pop 2 and push it into s2
            //Now, since left child of 2 exists: push 3 into s1
            //Right, doesn't exist so condition is false
            //Now, s1 would contain 3, we push 3 into s2 
        }

        while(!s2.empty()){
            ans.push_back(s2.top()->val);
            s2.pop();
        }
        return ans;   
    }
};




//Recursive approach
class Solution {
public:
    vector<int> ans;
    vector<int> postorderTraversal(TreeNode* root) {

        if(!root){
            return {};
        }

        postorderTraversal(root->left);
        postorderTraversal(root->right);
        ans.push_back(root->val);

        return ans;        
    }
};



