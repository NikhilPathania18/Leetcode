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
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        if(head==NULL||head->next==NULL)
            return head;
        int gNo=1;
        int no=0;
        ListNode* ptr=head;
        ListNode* currPrev=ptr;
        int i=0;
        ListNode* temp=ptr;
        while(ptr!=NULL)
        {
            if(gNo%2==0)
            {
                // return NULL;
                temp=ptr;
                ListNode* prev,*front;
                prev=front=NULL;
                i=0;
                while(ptr!=NULL&&i<gNo)
                {
                    front=ptr->next;
                    ptr->next=prev;
                    prev=ptr;
                    ptr=front;
                    i++;
                }
                currPrev->next=prev;
                temp->next=front;
                ptr=front;
                if(ptr==NULL&&i%2==1)
                {
                    ptr=currPrev->next;
                    ListNode* prev,*front;
                    prev=front=NULL;
                while(ptr!=NULL)
                {
                    front=ptr->next;
                    ptr->next=prev;
                    prev=ptr;
                    ptr=front;
                }
                currPrev->next=prev;
                }
            }
            else
            {
                i=0;
                while(ptr!=NULL&&i<gNo)
                {
                    currPrev=ptr;
                    ptr=ptr->next;
                    i++;
                }
                if(ptr==NULL&&i%2==0)
                {
                    ptr=temp->next;
                    ListNode* prev,*front;
                    prev=front=NULL;
                while(ptr!=NULL)
                {
                    front=ptr->next;
                    ptr->next=prev;
                    prev=ptr;
                    ptr=front;
                }
                temp->next=prev;
                }
            }
            gNo++;
        }
        return head;
    }
};