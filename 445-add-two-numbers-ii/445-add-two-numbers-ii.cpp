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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1,s2;
        ListNode* ptr1=l1,*ptr2=l2;
        while(ptr1||ptr2)
        {
            if(ptr1)
            {
                s1.push(ptr1->val);
                ptr1=ptr1->next;
            }
            if(ptr2)
            {
                s2.push(ptr2->val);
                ptr2=ptr2->next;
            }
        }
        int carry=0;
        ListNode* head=NULL,*temp;
        while(!s1.empty()||!s2.empty())
        {
            int x=0,y=0;
            if(!s1.empty())
            {
                x=s1.top();
                s1.pop();
            }
            if(!s2.empty())
            {
                y=s2.top();
                s2.pop();
            }
            ListNode* node=new ListNode((x+y+carry)%10);
            carry=((x+y)+carry)/10;
            if(head==NULL)
            {
                head=node;
            }
            else
            {
                temp->next=node;
            }
            temp=node;
        }
        if(carry!=0)
        {
            ListNode* node=new ListNode(carry);
            temp->next=node;
        }
        ListNode* prev,*front;
        prev=front=NULL;
        while(head!=NULL)
        {
            front=head->next;
            head->next=prev;
            prev=head;
            head=front;
        }
        return prev;
    }
};