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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;

        bfs(root, 0, ans);

        return ans;
    }

    void bfs(TreeNode* root, int level, vector<vector<int>>& order){
        if(root == nullptr)
            return;
        
        if(order.size() == level)
            order.push_back({});
        
        order[level].push_back(root->val);
        level++;        
        bfs(root->left, level, order);
        bfs(root->right, level, order);
    }
};
