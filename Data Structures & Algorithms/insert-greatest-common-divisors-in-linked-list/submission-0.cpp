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

    int gcd(int i1, int i2){

        if(max(i1,i2) % min(i1,i2) == 0)
            return min(i1,i2);

        return gcd(min(i1, i2), max(i1,i2)%min(i1,i2));
    }


    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(head == nullptr)
            return head;

        ListNode* lead = head->next;
        ListNode* tail = head;

        while(lead != nullptr){
            int temp = gcd(tail->val, lead->val);
            ListNode* n = new ListNode(temp, lead);
            tail->next = n;
            tail = lead;
            lead = lead->next;
        }

        return head;
        
    }
};