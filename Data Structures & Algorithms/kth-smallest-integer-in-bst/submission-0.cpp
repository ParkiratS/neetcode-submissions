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
    int kthSmallest(TreeNode* root, int k) {
        stack<int> minStack;
        stackFiller(root, minStack);

        for(int i = 1; i<k; i++)
            minStack.pop();

        return minStack.top();
    }


    void stackFiller(TreeNode* root, stack<int>& s){
        if(!root)
            return;
        
        stackFiller(root->right, s);
        s.push(root->val);
        stackFiller(root->left, s);
    }
};
