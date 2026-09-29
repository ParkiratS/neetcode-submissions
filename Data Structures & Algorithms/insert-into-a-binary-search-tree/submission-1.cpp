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

    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* temp = root;

        if(!temp)
            return new TreeNode(val);

        while(true){
            if(temp->val < val){
                if(!(temp->right))
                    break;
                temp = temp->right;
            }


            else{
                if(!(temp->left))
                    break;
                temp = temp->left;
            }
        }

        if(val > temp->val)
            temp->right = new TreeNode(val);
        else
            temp->left = new TreeNode(val);
        

        return root;
    }
};