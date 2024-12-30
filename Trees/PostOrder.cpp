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
    void postorder(TreeNode* root, vector<int>& ans)
    {
        if(root == NULL) return;

        postorder(root -> left, ans);
        postorder(root -> right, ans);
        ans.push_back(root -> val);
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        postorder(root,ans);

        return ans;
    }
};

// Iterative
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> postorder;
        if(root == NULL) return postorder;

        stack<TreeNode*> st;
        st.push(root);

        while(!st.empty())
        {
            TreeNode* itr = st.top();
            st.pop();

            postorder.push_back(itr -> val);

            if(itr -> left) st.push(itr -> left);
            if(itr -> right) st.push(itr -> right);
        }
        reverse(postorder.begin(),postorder.end());
        
        return postorder;
    }
};