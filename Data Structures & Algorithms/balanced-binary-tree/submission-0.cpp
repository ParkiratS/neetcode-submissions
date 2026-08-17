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
    bool isBalanced(TreeNode* root) {
        bool ans = true;
        dfs(root, ans);
        return ans;
    }

    int dfs(TreeNode* root, bool& ans){
        if(!root)
            return 0;

        int right = dfs(root->right, ans);
        int left = dfs(root->left, ans);

        ans = (abs(right-left) <= 1) && ans;

        return max(right, left)+1;
    }
};
