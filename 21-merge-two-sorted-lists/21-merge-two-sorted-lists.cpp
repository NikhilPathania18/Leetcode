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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1&&!list2)
            return NULL;
        if(list1&&!list2)
            return list1;
        else if(list2&&!list1)
            return list2;
        
        ListNode* prev=NULL,*head=list1;
        while(list1&&list2)
        {
            if(list2->val<list1->val)
            {
                if(prev==NULL)
                {
                    ListNode* temp=list2;
                    list2=list2->next;
                    temp->next=list1;
                    head=temp;
                    prev=temp;
                }
                else
                {
                    prev->next=list2;
                    list2=list2->next;
                    prev=prev->next;
                    prev->next=list1;
                }
                
            }
            else
            {
                prev=list1;
                list1=list1->next;
            }
        }
        if(!list1)
            prev->next=list2;
        
        return head;
            
    }
};