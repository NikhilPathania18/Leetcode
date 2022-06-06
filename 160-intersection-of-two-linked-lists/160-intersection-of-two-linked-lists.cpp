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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*> a;
        while(headA!=NULL)
        {
            a.insert(headA);
            headA=headA->next;
        }
        while(headB!=NULL)
        {
            if(a.find(headB)!=a.end())
                return headB;
            headB=headB->next;
        }
        return NULL;
    }
};