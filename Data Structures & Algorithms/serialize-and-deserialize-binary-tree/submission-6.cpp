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

class Codec {
public:

    void encodeTree(string& ans, TreeNode* root){
        if(!root){
            ans+='.';
            return;
        }

        ans+='('+to_string(root->val)+')';
        encodeTree(ans, root->left);
        encodeTree(ans, root->right);
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans="";
        encodeTree(ans, root);
        cout<<ans<<endl;
        return ans;
    }

    TreeNode* decodeTree(const string& data, int& index){
        if(data[index] == '.'){
            index++;
            return nullptr;
        }

        index++;
        string temp = "";
        while(data[index] != ')'){
            temp+=data[index];
            index++;
        }

        index++;
        return new TreeNode(stoi(temp), decodeTree(data, index), decodeTree(data, index));
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int index = 0;
        return decodeTree(data, index);
    }
};
