class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(root == NULL) return ans;
        
        queue<TreeNode*> q;
        q.push(root);           
        
        while(!q.empty())
        {
            int k = q.size();

            for(int i=0;i<k;i++)
            {
                auto itr = q.front();
                q.pop();
                
                if(i == k-1) ans.push_back(itr -> val);

                if(itr -> left) q.push(itr -> left);
                if(itr -> right) q.push(itr -> right);
            }
        }
        
        return ans;
    }
};