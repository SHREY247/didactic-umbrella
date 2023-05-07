/*Given the root of an n-ary tree, return the preorder traversal of its nodes' values.
Nary-Tree input serialization is represented in their level order traversal. Each group 
of children is separated by the null value (See examples)

Example:
Input: root = [1,null,3,2,4,null,5,6]
Output: [1,3,5,6,2,4]
 */

//Use recursive approach

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    // To store the output result...
    vector<int> output;
    void traverse(Node* root) {
        // Base case: if the tree is empty...
        if(root == NULL) return;
        // Push the value of the root node to the output...
        output.push_back(root->val);
        // Recursively traverse each node in the children array...
        for(auto node:root->children)
            traverse(node);
    }
    vector<int> preorder(Node* root) {
        output.clear();
        traverse(root);
        return output;
    }
};
