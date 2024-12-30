class Solution {
  public:
    void solve(vector<int>& v,vector<vector<int>>& ans,Node* root){
        if(root -> left == NULL && root -> right == NULL){
            ans.push_back(v);
            return;
        }  
        
        if(root -> left)
        {
            v.push_back(root -> left -> data);
            solve(v,ans,root -> left);
            v.pop_back();
        }
        if(root -> right)
        {
            v.push_back(root -> right -> data);
            solve(v,ans,root -> right);
            v.pop_back();
        }
    }
    
    vector<vector<int>> Paths(Node* root) {
        vector<vector<int>> ans;
        vector<int> v;
        
        v.push_back(root -> data);
        
        solve(v,ans,root);
        return ans;
    }
};