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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head||!head->next)  return head;
        
        ListNode* prev=NULL,*newHead=NULL;
        while(head&&head->next)
        {
            if(head->val==head->next->val)
            {
                while(head->next&&head->val==head->next->val)
                    head=head->next;
                if(!prev)
                    newHead=head->next;
                else
                    prev->next=head->next;
                head=head->next;
            }
            else
            {
                if(!prev)
                {
                    newHead=head;
                }
                prev=head;
                head=head->next;
            }
        }
        return newHead;
    }
};