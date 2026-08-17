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
    vector<int> rightSideView(TreeNode* root) {

        vector<int> ans;
        bfs(root, 1, ans);
        return ans;
        
    }

    void bfs(TreeNode* root, int level, vector<int>& ans){
        if(!root)
            return;

        if(ans.size() < level)
            ans.push_back(root->val);
        
        level++;
        bfs(root->right, level, ans);
        bfs(root->left, level, ans);
    }
};
