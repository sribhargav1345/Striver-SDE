// Just add left boundaries, leaves, right boundaries... leaf can be added by inorder traversal
class Solution {
  public:
  
    bool isLeaf(Node* root){
        return (!root -> left && !root -> right);
    }
    
    void addLeftBoundary(Node* root,vector<int>& ans)
    {
        Node* curr = root -> left;
        
        while(curr != NULL)
        {
            if (!isLeaf(curr)) {
                ans.push_back(curr->data);
            }
            
            if(curr -> left) curr = curr -> left;
            else curr = curr -> right;      // Right will always present, as it's not leaf
        }
    }
    
    void addRightBoundary(Node* root, vector<int>& ans)
    {
        Node* curr = root -> right;
        
        vector<int> temp;
        while(curr != NULL)
        {
            if(!isLeaf(curr)){
                temp.push_back(curr -> data);
            }
            
            if(curr -> right) curr = curr -> right;
            else curr = curr -> left;
        }
        
        for(int i=temp.size()-1;i>=0;i--){
            ans.push_back(temp[i]);
        }
    }
    
    void addLeaf(Node* root,vector<int>& ans){
        if(isLeaf(root)){
            ans.push_back(root -> data);
            return;
        }
        
        if(root -> left) addLeaf(root -> left,ans);
        if(root -> right) addLeaf(root -> right,ans);
    }
    
    vector<int> boundaryTraversal(Node *root) {
        // code here
        vector<int> ans;
        if(root ==NULL) return ans;
        
        if(!isLeaf(root)) ans.push_back(root -> data);
        
        addLeftBoundary(root,ans);
        addLeaf(root,ans);
        addRightBoundary(root,ans);
        
        return ans;
    }
};