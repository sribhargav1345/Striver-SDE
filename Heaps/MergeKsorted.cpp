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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* ans;
        priority_queue<int,vector<int>,greater<int>> pq;

        int n = lists.size();
        for(int i=0;i<n;i++)
        {
            ListNode* a = lists[i];
            while(a != NULL)
            {
                pq.push(a -> val);
                a = a -> next;
            }
        }

        ListNode* op;

        if(pq.empty()) return NULL;

        op = new ListNode(pq.top());
        ListNode* q = op;

        while(!pq.empty())
        {
            ListNode* p = new ListNode(pq.top());
            q -> next = p;

            q = p;
            pq.pop();
        }
        return op -> next;
    }
};