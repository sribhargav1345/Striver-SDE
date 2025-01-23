class Solution {
  public:
    // Function to reverse a doubly linked list
    DLLNode* reverseDLL(DLLNode* head) {
        // Your code here
        DLLNode* a = head;
        
        if(a -> next == NULL){
            return head;
        }
        
        DLLNode* pre = NULL;
        DLLNode* curr = head;
        
        while(curr){
            DLLNode* temp = curr -> next;
            
            curr -> next = pre;
            curr -> prev = temp;
            
            pre = curr;
            curr = temp;
        }
        return pre;
    }
};