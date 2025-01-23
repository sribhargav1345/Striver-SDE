class Solution {
  public:
    // Function to insert a new node at given position in doubly linked list.
    Node *addNode(Node *head, int pos, int data) {
        // code here
        Node* op = new Node(data);
        int ct = 0;
        
        Node* a = head;
        while(a != NULL){
            a = a -> next;
            ct++;
            
            if(ct == pos){
                break;
            }
        }
        
        if(a -> next == NULL){
            a -> next = op; 
            op -> prev = a;
            
            return head;
        }
        
        Node* temp = a -> next;
        a -> next = op;
        op -> next = temp;
        
        op -> prev = a;
        temp -> prev = op;
        
        return head;
    }
};