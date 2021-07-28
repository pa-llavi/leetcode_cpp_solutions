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
    bool ans;
    int check(TreeNode* root) {
        if(root==NULL) {
            return 0;
        }
        if(!ans) {
            return 0;
        }
        
        int h1 = check(root->left), h2 = check(root->right); 
        if(abs(h1 - h2) > 1){
            ans = false;
        }
        
        return max(h1, h2)+1;
    }
    
    bool isBalanced(TreeNode* root) {
        ans = true;
        int tmp = check(root);
        return ans;
    }
};
