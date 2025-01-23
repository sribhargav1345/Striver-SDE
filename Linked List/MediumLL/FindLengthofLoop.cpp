class Solution {
  public:
    // Function to find the length of a loop in the linked list.
    int countNodesinLoop(Node *head) {
        Node* slow = head;
        Node* fast = head;
        
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
            return 0;
        }
        
        Node* a = head;
        Node* b = slow;
        
        while(a != b){
            a = a -> next;
            b = b -> next;
        }
        
        int count = 1;
        b = b -> next;
        
        while(a != b){
            b = b -> next;
            count += 1;
        }
        return count;
        
        
    }
};