class Solution {
public:
    TreeNode* search(TreeNode* root, TreeNode* target){
        if(root == NULL) return nullptr;
        
        if(root == target) return root;
        
        TreeNode* leftResult = search(root->left, target);
        if (leftResult != nullptr) return leftResult;
    
        return search(root->right, target);
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        map<TreeNode*,TreeNode*> mp;
        vector<int> v;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty())
        {
            int p = q.size();
            for(int i=0;i<p;i++)
            {
                auto itr = q.front();
                q.pop();
                
                if(itr -> left)
                {
                    mp[itr -> left] = itr; 
                    q.push(itr -> left);
                }
                if(itr -> right)
                {
                    mp[itr -> right] = itr; 
                    q.push(itr -> right);
                }
            }
        }
        
        // coming to 2nd bfs
        TreeNode* a = search(root, target);
        queue<pair<TreeNode*,int>> pq;
        
        pq.push({a,0});
        
        set<int> visited;
        
        visited.insert(a -> val);
        
        while(!pq.empty())
        {
            auto it = pq.front();
            pq.pop();
            
            TreeNode* itr = it.first;
            int dis = it.second;
            
            if(dis == k) v.push_back(itr-> val);
            
            if(itr -> left)
            {
                if(visited.find(itr -> left -> val) == visited.end()){
                    visited.insert(itr -> left -> val);
                    pq.push({itr-> left,dis+1});
                }
            }
            if(itr -> right)
            {
                if(visited.find(itr -> right -> val) == visited.end()){
                    visited.insert(itr -> right -> val);
                    pq.push({itr-> right,dis+1});
                }
            }
            
            if(itr != root){
                if(visited.find(mp[itr]-> val) == visited.end()){
                    visited.insert(mp[itr]-> val);
                    pq.push({mp[itr],dis+1});
                }
            }
        }
        return v;
    }
};