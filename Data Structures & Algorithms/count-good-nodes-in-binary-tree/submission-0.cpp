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
    int goodNodes(TreeNode* root) {
        return nodeCounter(root, root->val);
    }

    int nodeCounter(TreeNode* root, int max){
        if(!root)
            return 0;
        
        if(!(max > root->val))
            return nodeCounter(root->right, root->val) + nodeCounter(root->left, root->val) + 1;
        
        else
            return nodeCounter(root->right, max) + nodeCounter(root->left, max);
        
    }
};
