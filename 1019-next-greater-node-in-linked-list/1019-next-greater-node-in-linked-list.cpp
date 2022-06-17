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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> values;
        while(head)
        {
            values.push_back(head->val);
            head=head->next;
        }
        vector<int> ans(values.size(),0);
        stack<int> stk;
        stk.push(0);
        int temp=0;
        for(int i=1;i<values.size();i++)
        {
            while(!stk.empty()&&values[i]>values[stk.top()])
            {
                ans[stk.top()]=values[i];
                stk.pop();
            }
            stk.push(i);
        }
        return ans;
    }
};