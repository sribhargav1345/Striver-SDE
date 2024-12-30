class Solution {
  public:
    int minValue(Node* root) {
        int mini = INT_MAX;
        while(root){
            mini = min(root -> data, mini);
            root = root -> left;
        }
        return mini;
    }
};