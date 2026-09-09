/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:

    void traverse(ListNode* hA, ListNode* hB){
        if(hA == nullptr || hB == nullptr || hA == hB)
            return;
        
        traverse(hA->next, hB->next);
    }

    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        ListNode* hA = headA;
        ListNode* hB = headB;

        while(hA != nullptr){
            hB = headB;
            while(hB != nullptr){
                if(hB == hA)
                    return hA;
                hB = hB->next;
            }
            hA = hA->next;
        }

        return nullptr;
        
    }
};