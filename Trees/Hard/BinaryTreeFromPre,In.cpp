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
    TreeNode* buildTree(vector<int>& preorder,int prestart,int preend,vector<int>& inorder,int instart,int inend,map<int,int>& mp){
        if(prestart > preend || instart > inend){
            return NULL;
        }

        TreeNode* root = new TreeNode(preorder[prestart]);

        int inRoot = mp[root -> val];
        int left = inRoot - instart;

        root -> left = buildTree(preorder, prestart+1,prestart+left, inorder, instart, inRoot-1,mp);
        root -> right = buildTree(preorder, prestart+left+1,preend, inorder, inRoot+1, inend,mp);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int> mp;
        int n = preorder.size();

        for(int i=0;i<n;i++)
        {
            mp[inorder[i]] = i;
        }

        TreeNode* root = buildTree(preorder,0,n-1,inorder,0,n-1,mp);
        return root;
    }
};