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
        if(head==NULL||head->next==NULL||head->next->next==NULL)
            return;
        ListNode* first=head,*second=head,*back=NULL;
        while(second!=NULL&&second->next!=NULL)
        {
            back=first;
            first=first->next;
            second=second->next->next;
        }
        if(second!=NULL)
        {
            back=first;
            first=first->next;
        }
        back->next=NULL;
        ListNode* prev=NULL,*front=NULL;
        while(first!=NULL)
        {
            front=first->next;
            first->next=prev;
            prev=first;
            first=front;
        }
        ListNode* ptr1=head,*ptr2=prev;
        ListNode* temp=NULL;
        while(ptr1&&ptr2)
        {
                temp=ptr2->next;
                ptr2->next=ptr1->next;
                ptr1->next=ptr2;
                ptr1=ptr2->next;
                ptr2=temp;
        }
        
    }
};