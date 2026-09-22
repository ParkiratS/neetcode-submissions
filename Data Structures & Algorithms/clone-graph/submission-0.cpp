/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* traverse(Node* root, unordered_map<Node*, Node*>& seen){
        if(!root)
            return nullptr;
        
        Node* temp = new Node(root->val);
        seen[root] = temp;

        for(Node* child:root->neighbors){
            if(seen.find(child) == seen.end()){
                traverse(child, seen);
                temp->neighbors.push_back(seen[child]);
            }
            else
                temp->neighbors.push_back(seen[child]);
        }

        return temp;
    }

    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*> seen;

        return traverse(node, seen);
    }
};
