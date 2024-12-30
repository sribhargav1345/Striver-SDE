/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // LCA 
        if(root == NULL) return NULL;

        int ans = root -> val;
        if(root -> val < p -> val && root -> val < q -> val){
            return lowestCommonAncestor(root -> right,p,q);
        }
        else if(root -> val > p -> val && root -> val > q -> val){
            return lowestCommonAncestor(root -> left,p,q);
        }

        return root;
    }
};