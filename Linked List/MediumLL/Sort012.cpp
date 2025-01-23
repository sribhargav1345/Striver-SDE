class Solution {
  public:
    // Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node* head) {
        
        Node* zero = new Node(-1);
        Node* one = new Node(-1);
        Node* two = new Node(-1);
        
        Node* z = zero;
        Node* o = one;
        Node* t = two;
        
        Node* a = head;
        while(a != NULL)
        {
            if(a -> data == 0){
                zero -> next = a;
                zero = zero -> next;
            }
            else if(a -> data == 1){
                one -> next = a;
                one = one -> next;
            }
            else if(a -> data == 2){
                two -> next = a;
                two = two -> next;
            }
            
            a = a -> next;
        }
        
        two -> next = NULL;
        one -> next = t -> next;
        zero -> next = o -> next;
        
        return (z -> next);
    }
};