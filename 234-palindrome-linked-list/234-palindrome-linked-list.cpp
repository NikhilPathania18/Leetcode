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
    bool isPalindrome(ListNode* head) {
        if(head==NULL||head->next==NULL)
            return true;
        
        ListNode* front=NULL,*prev=NULL,*ptr=head;
        ListNode *second=head;
        while(second!=NULL&&second->next!=NULL)
        {
            second=second->next->next;
            front=ptr->next;
            ptr->next=prev;
            prev=ptr;
            ptr=front;
        }
        if(second&&second->next==NULL)
            ptr=ptr->next;
        while(prev!=NULL&&ptr!=NULL)
        {
            if(prev->val!=ptr->val) return false;
            ptr=ptr->next;
            prev=prev->next;
        }
        return true;
    }
};