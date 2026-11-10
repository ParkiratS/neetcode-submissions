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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* beg = nullptr;
        ListNode* end = nullptr;
        ListNode* before = nullptr;
        ListNode* after = nullptr;
        ListNode* curr = head;

        ListNode* temp = nullptr;
        int i = 1;

        while (curr && i <= right) {
            if (i == left - 1)
                before = curr;

            if (i == left)
                beg = curr;

            if (i >= left){
                ListNode* temp2 = curr->next;
                curr->next = temp;
                temp = curr;
                curr = temp2;
            }
            else
                curr = curr->next;

            i++;
        }


        end = temp;
        after = curr;
        beg->next = after;

        if(!before)
            head = end;
        else
            before->next = end;

        return head;   
    }
};