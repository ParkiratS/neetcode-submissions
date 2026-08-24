/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    unordered_map<Node*, Node*> m;

    Node* traverse(Node* head){
        if(!head)
            return nullptr;

        Node* temp;

        if(m.find(head) != m.end())
            temp = m[head];
        else{
            temp = new Node(head->val);
            m[head] = temp;
        }

        if(!head->random)
            temp->random = nullptr;
        else if(m.find(head->random) != m.end())
            temp->random = m[head->random];
        else{
            temp->random = new Node(head->random->val);
            m[head->random] = temp->random;
        }

        temp->next = traverse(head->next);

        return temp;

    }

    Node* copyRandomList(Node* head) {
        return traverse(head);
    }
};
