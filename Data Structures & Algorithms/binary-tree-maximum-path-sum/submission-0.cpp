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
    int traverse(TreeNode* root, int& sum){
        
        int left, right;

        if(root->right == nullptr)
            right = INT_MIN;
        else
            right = traverse(root->right, sum);
        
        if(root->left == nullptr)
            left = INT_MIN;
        else
            left = traverse(root->left, sum);

        if(left > 0 && right > 0){
            sum = max(sum, root->val + left + right);
            return root->val + max(left, right);
        }
        else if(left < 0 && right < 0){
            sum = max(sum, root->val);
            return root->val;
        }
        else{
            int temp = max(left, right);
            sum = max(sum, root->val + temp);
            return root->val + temp;
        }
        
    }

    int maxPathSum(TreeNode* root) {
        int sum = INT_MIN;
        traverse(root, sum);
        return sum;
    }
};
