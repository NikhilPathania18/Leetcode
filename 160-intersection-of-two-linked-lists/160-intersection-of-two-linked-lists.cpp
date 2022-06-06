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
    ListNode *getIntersectionNode(ListNode *head1, ListNode *head2) {
        ListNode* ptr1=head1,*ptr2=head2;
        while(ptr1!=ptr2)
        {
            if(ptr1==NULL)
                ptr1=head2;
            else
                ptr1=ptr1->next;
            if(ptr2==NULL)
                ptr2=head1;
            else
                ptr2=ptr2->next;
        }
        return ptr1;
    }
};