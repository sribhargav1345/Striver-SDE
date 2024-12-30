/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {

        // Level order traversal is a kind of BFS, we need a queue for it.

        vector<vector<int>> ans;
        TreeNode* a = root;

        if(a==NULL) return ans;

        queue<TreeNode*> q;
        q.push(a);

        while(!q.empty())
        {
            vector<int> v;
            int k = q.size();

            for(int i=0;i<k;i++)
            {
                TreeNode* f = q.front();
                v.push_back(f -> val);

                q.pop();
                if(f -> left !=NULL) q.push(f -> left);
                if(f -> right != NULL) q.push(f -> right);
            }
            ans.push_back(v);
        }
        return ans;
        
    }
};