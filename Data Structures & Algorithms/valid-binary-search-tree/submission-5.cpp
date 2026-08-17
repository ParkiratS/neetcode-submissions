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
    bool isValidBST(TreeNode* root) {
        return validateNode(root, LONG_MIN, LONG_MAX);
    }

    bool validateNode(TreeNode* root, long lBound, long rBound){
        if(!root)
            return true;
        
        if(!(root->val > lBound && root->val < rBound))
            return false;
        
        return (validateNode(root->left, lBound, root->val) && validateNode(root->right, root->val, rBound));

    }

    
};

