class Solution {
public:
    ListNode* mergeSort(ListNode* left,ListNode* right){
        ListNode* dummy = new ListNode(-1);
        ListNode* a = dummy;

        while(left != NULL && right != NULL){
            if(left -> val <= right -> val){
                a -> next = left;
                left = left -> next;
            }
            else{
                a -> next = right;
                right = right -> next;
            }

            a = a -> next;
        }

        if(left != NULL){
            a -> next = left;
        }
        if(right != NULL){
            a -> next = right;
        }

        return (dummy -> next);
    }

    ListNode* findMid(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head -> next;      // Check this

        while(fast != NULL && fast -> next != NULL){
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        return slow;
    }

    ListNode* sortList(ListNode* head) {
        if(head == NULL || head -> next == NULL){
            return head;
        }

        ListNode* mid = findMid(head);

        ListNode* right = mid -> next;
        mid -> next = NULL;
        ListNode* left = head;

        left = sortList(left);
        right = sortList(right);

        return mergeSort(left, right);
    }
};