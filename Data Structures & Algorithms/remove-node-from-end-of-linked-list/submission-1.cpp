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
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        int listSize = 0;
        ListNode* temp = head;

        while(temp != nullptr){
            listSize++;
            temp = temp->next;
        }

        if(n == listSize)
            return head->next;

        ListNode* nNode = head;
        ListNode* prev;

        for(int i = 0; i<listSize-n; i++){
            prev = nNode;
            nNode = nNode->next;
        }

        ListNode* nextNode = nNode->next;
        prev->next = nextNode;
        return head;
    }
};
