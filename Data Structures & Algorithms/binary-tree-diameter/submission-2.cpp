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

    // int rightDepth(TreeNode* root){
    //     if(root == nullptr)
    //         return 0;
        
    //     return rightDepth(root->right) + 1;
    // }

    // int leftDepth(TreeNode* root){
    //     if(root == nullptr)
    //         return 0;
        
    //     return leftDepth(root->left) + 1;
    // }

    int deepest(TreeNode* root){
        if(root == nullptr)
            return 0;
        
        int right = deepest(root->right);
        int left = deepest(root->left);

        return max(right, left)+1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if(root == nullptr)
            return 0;
        
        int depth = deepest(root->right) + deepest(root->left);
        int maxChild = max(diameterOfBinaryTree(root->right), diameterOfBinaryTree(root->left));
        return max(maxChild, depth);        
    }
};
