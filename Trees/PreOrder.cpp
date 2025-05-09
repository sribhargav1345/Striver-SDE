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
    void preorder(TreeNode* root, vector<int>& ans)
    {
        if(root == NULL) return;

        ans.push_back(root -> val);
        preorder(root -> left, ans);
        preorder(root -> right, ans);
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        preorder(root,ans);

        return ans;
    }
};

// Iterative
vector<int> preorder;
if(root == NULL) return preorder;

stack<TreeNode*> st;
st.push(root);

while(!st.empty())
{
    TreeNode* itr = st.top();
    st.pop();

    preorder.push_back(itr -> val);

    if(itr -> right) st.push(itr -> right);
    if(itr -> left) st.push(itr -> left);
}
return preorder;