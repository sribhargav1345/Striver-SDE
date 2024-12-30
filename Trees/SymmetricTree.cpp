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
    bool solve(TreeNode* root,TreeNode* root2){
        if(root == NULL && root2 == NULL){
            return true;
        }

        if(root == NULL || root2 == NULL) return false;

        return (root -> val == root2 -> val) && solve(root -> left, root2 -> right) && solve(root -> right, root2 -> left);
    }
    
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;

        return solve(root,root);
    }
};