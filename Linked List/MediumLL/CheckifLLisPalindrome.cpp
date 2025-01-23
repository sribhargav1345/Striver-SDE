// Brute force is to use stack and compare the values
// Above takes O(n) time

// Optimal -> reverse half linkedlist and check

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        ListNode* last_first;
        while(fast != NULL && fast -> next != NULL){
            last_first = slow;
            slow = slow -> next;
            fast = fast -> next -> next;
        }

        if(fast != NULL){
            last_first = slow;
            slow = slow -> next;        // Odd case, let's reverse from here
        }

        ListNode* prev = NULL;
        ListNode* curr = slow;
        
        while(curr){
            ListNode* temp = curr -> next;

            curr -> next = prev;
            prev = curr;
            curr = temp;
        }
        last_first -> next = prev;
        
        ListNode* a = head;
        ListNode* b = prev;

        while(b != NULL){
            if(a -> val != b -> val){
                return false;
            }
            a = a -> next;
            b = b -> next;
        }
        return true;
    }
};

