class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        int flag = 0;
        while(fast != NULL && fast -> next != NULL){
            slow = slow -> next;
            fast = fast -> next -> next;

            if(fast == slow){
                flag = 1;
                break;
            }
        }
    
        if(flag == 0){
            ListNode* op = new ListNode(-1);
            return NULL;
        }

        ListNode* a = head;
        ListNode* b = slow;

        while(a != b){
            a = a -> next;
            b = b -> next;
        }

        return a;
    }
};