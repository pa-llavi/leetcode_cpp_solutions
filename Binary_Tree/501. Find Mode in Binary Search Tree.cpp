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
    void count(TreeNode* root, unordered_map<int, int>& mp) {
        if(!root) 
            return;
        
        mp[root->val]++;
        count(root->left, mp);
        count(root->right, mp);
    }
    
    vector<int> findMode(TreeNode* root) {
        unordered_map<int, int> mp;
        count(root, mp);
        
        vector<int> res;
        int mx = 0;
        for(auto x : mp) {
            mx = max(mx, x.second);
        }
        
        for(auto x : mp) {
            if(x.second == mx)
                res.push_back(x.first);
        }
        
        return res;
    }
};
