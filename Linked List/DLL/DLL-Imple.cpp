class Solution {
  public:
    Node* constructDLL(vector<int>& arr) {
        // code here
        Node* a = new Node(arr[0]);
        Node* b = a;
        
        int n = arr.size();
        for(int i=1;i<n;i++)
        {
            Node* p = new Node(arr[i]);
            a -> next = p;
            p -> prev = a;
            a = a -> next;
        }
        return b;
    }
};