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
    ListNode* ptr=NULL;
    int count=0;
    Solution(ListNode* head) {
        ptr=head;
        while(head!=NULL)
        {
            count++;
            head=head->next;
        }
    }
    
    int getRandom() {
        int random=(rand()%count);
        ListNode* head=ptr;
        int i=0;
        while(i<random)
        {
            head=head->next;
            i++;
        }
        return head->val;
            
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */