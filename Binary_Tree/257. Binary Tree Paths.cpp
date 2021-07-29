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
    vector<string> res;
    void func(TreeNode* root, string op) {
        //base
        if(!root->left && !root->right) {
            res.push_back(op);
        }
        
        if(root->left) {
            string op1 = op + "->" + to_string(root->left->val);
            func(root->left, op1);
        }
        if(root->right) {
            string op1 = op + "->" + to_string(root->right->val);
            func(root->right, op1);
        }
    }
        
    vector<string> binaryTreePaths(TreeNode* root) {
        string op = to_string(root->val);
        func(root, op);
        return res;
    }
};
