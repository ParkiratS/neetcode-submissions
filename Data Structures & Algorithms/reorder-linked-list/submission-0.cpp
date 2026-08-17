/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    void reorderList(ListNode* head) {
        stack<ListNode*> nodeStack;

        ListNode* temp = head;
        ListNode* prevNode = nullptr;

        while(temp != nullptr){
            nodeStack.push(temp);
            temp = temp->next;
        }

        temp = head;

        while(true){
            if(nodeStack.top() == temp || temp->next == prevNode){
                temp->next = nullptr;
                break;
            }
            else{
                nodeStack.top()->next = temp->next;
                temp->next = nodeStack.top();
                prevNode = nodeStack.top();
                nodeStack.pop();
                temp = temp->next;
                temp = temp->next;
            }
        }

        
    }
};
