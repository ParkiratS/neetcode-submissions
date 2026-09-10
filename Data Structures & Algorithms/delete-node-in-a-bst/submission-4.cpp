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

    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode* prev = root;
        TreeNode* curr = root;

        while(curr != nullptr && curr->val != key){
            prev = curr;
            if(curr->val < key)
                curr = curr->right;
            else
                curr = curr->left;
        }

        if(curr == nullptr)
            return root;

        if(curr == root){
            if(curr->left == nullptr){
                root = curr->right;
                return root;
            }
            root = curr->left;
            prev = curr->left;

        }
        else{
            if(curr == prev->left){
                if(curr->left == nullptr){
                    prev->left = curr->right;
                    return root;
                }
                prev->left = curr->left;
                prev = prev->left;
            }
            else{
                if(curr->left == nullptr){
                    prev->right = curr->right;
                    return root;
                }
                prev->right = curr->left;
                prev = prev->right;
            }
        }

        while(prev->right != nullptr)
            prev = prev->right;
        
        prev->right = curr->right;

        return root;

        
    }
};