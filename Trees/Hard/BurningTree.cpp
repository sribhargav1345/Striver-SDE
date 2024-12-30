class Solution {
  public:
    Node* search(Node* root, int target){
        if(root == NULL) return nullptr;
        
        if(root -> data == target) return root;
        
        Node* leftResult = search(root->left, target);
        if (leftResult != nullptr) return leftResult;
    
        return search(root->right, target);
    }
    
    int minTime(Node* root, int target) {
        // code here
        map<Node*,Node*> mp;
        
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty())
        {
            int k = q.size();
            for(int i=0;i<k;i++)
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
        Node* a = search(root, target);
        queue<pair<Node*,int>> pq;
        
        pq.push({a,0});
        
        set<int> visited;
        int maxi = 0;
        
        visited.insert(a -> data);
        
        while(!pq.empty())
        {
            auto it = pq.front();
            pq.pop();
            
            Node* itr = it.first;
            int dis = it.second;
            
            maxi = max(maxi,dis);
            
            if(itr -> left)
            {
                if(visited.find(itr -> left -> data) == visited.end()){
                    visited.insert(itr -> left -> data);
                    pq.push({itr-> left,dis+1});
                }
            }
            if(itr -> right)
            {
                if(visited.find(itr -> right -> data) == visited.end()){
                    visited.insert(itr -> right -> data);
                    pq.push({itr-> right,dis+1});
                }
            }
            
            if(itr != root){
                if(visited.find(mp[itr]-> data) == visited.end()){
                    visited.insert(mp[itr]-> data);
                    pq.push({mp[itr],dis+1});
                }
            }
        }
        return maxi;
    }
};