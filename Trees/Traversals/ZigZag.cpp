// Just one flag variable and done
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;

        if(root == NULL) return ans;

        queue<pair<TreeNode*,int>> q;
        q.push({root,1});

        int flag = 0;

        while(!q.empty())
        {
            int k = q.size();
            vector<int> v;

            for(int i=0;i<k;i++)
            {
                auto itr = q.front();
                q.pop();

                if(itr.first -> left != NULL) q.push({itr.first -> left,1});
                if(itr.first -> right != NULL) q.push({itr.first -> right,1});

                v.push_back(itr.first -> val);
            }
            flag ^= 1;
            
            if(flag == 0) reverse(v.begin(),v.end());
            ans.push_back(v);
        }
        return ans;
    }
};