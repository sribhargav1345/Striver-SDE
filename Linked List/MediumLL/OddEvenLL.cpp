class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head == NULL || head->next == NULL || head->next->next == NULL) {
            return head; // Edge cases: empty list, single node, or two nodes
        }

        ListNode* odd = head;         // Pointer to track odd-indexed nodes
        ListNode* even = head->next; // Pointer to track even-indexed nodes
        ListNode* evenHead = even;    // Save the start of the even list

        // Iterate through the list, alternating between odd and even nodes
        while (even != NULL && even->next != NULL) {
            odd->next = even->next;   // Link odd to the next odd node
            odd = odd->next;          // Move odd pointer forward

            even->next = odd->next;   // Link even to the next even node
            even = even->next;        // Move even pointer forward
        }

        odd->next = evenHead;         // Connect the end of the odd list to the start of the even list
        return head;                  // Return the head of the reordered list
    }
};
