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
    ListNode* partition(ListNode* ptr, int x) {
        ListNode *curr, *prev;
    curr = prev = NULL;
    ListNode *head = ptr;
    while (ptr != NULL)
    {
        if (ptr->val < x)
        {
            if (curr == NULL)
            {
                if (prev == NULL)
                {
                    curr = ptr;
                    prev = ptr;
                    ptr = ptr->next;
                }
                else
                {
                    prev->next = ptr->next;
                    ptr->next = head;
                    curr = ptr;
                    head = curr;
                    ptr = prev->next;
                }
            }

            else
            {
                if(prev==curr)
                {
                    prev=ptr;
                    curr=ptr;
                    ptr=ptr->next;
                }
                else{
                    prev->next = ptr->next;
                    ptr->next = curr->next;
                    curr->next = ptr;
                    ptr = prev->next;
                    curr = curr->next;
                }
            }
        }
        else
        {
            prev = ptr;
            ptr = ptr->next;
        }
    }
    return head;
    }
};