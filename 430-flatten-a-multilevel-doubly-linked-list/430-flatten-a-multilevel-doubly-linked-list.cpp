/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* solve(Node* ptr)
    {
        if(ptr==NULL)
            return NULL;
        while(ptr->next!=NULL)
        {
            if(ptr->child!=NULL)
            {
                Node* temp=ptr->next;
                ptr->next=ptr->child;
                ptr->next->prev=ptr;
                ptr->child=NULL;
                Node* temp2=solve(ptr->next);
                if(temp2)
                temp2->next=temp;
                if(temp)
                    temp->prev=temp2;
                ptr=temp;
            }
            else
            ptr=ptr->next;
        }
        if(ptr->child!=NULL)
        {
            ptr->next=ptr->child;
            ptr->child->prev=ptr;
            ptr->child=NULL;
            return solve(ptr->next);
        }
        return ptr;
    }
    Node* flatten(Node* head) {
        if(head==NULL)
            return NULL;
        solve(head);
        return head;
        
    }
};