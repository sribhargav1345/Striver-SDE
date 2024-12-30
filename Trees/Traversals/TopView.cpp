// Just a map and queue

class Solution {
  public:
    
    vector<int> topView(Node *root) {
        // code here
        vector<int> ans;
        if(root == NULL) return ans;
        
        map<int,int> mp;
        
        queue<pair<Node*,int>> q;
        q.push({root,0});           // 0 is it's vertical level
        
        while(!q.empty())
        {
            auto itr = q.front();
            q.pop();
            
            if(mp.find(itr.second) == mp.end()) mp[itr.second] = itr.first -> data;
            
            if(itr.first -> left) q.push({itr.first -> left,itr.second - 1});
            if(itr.first -> right) q.push({itr.first -> right,itr.second + 1});
        }
        
        for(auto x:mp){
            ans.push_back(x.second);
        }
        
        return ans;
    }
};