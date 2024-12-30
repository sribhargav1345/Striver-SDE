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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* no = new TreeNode(val);

        if(root == NULL) return no;

        TreeNode* cur = root;
        while(true)
        {
            if(cur -> val > val){
                if(cur -> left) cur = cur -> left;
                else {
                    cur -> left = no;
                    return root;
                }
            }
            else{
                if(cur -> right) cur = cur -> right;
                else{
                    cur -> right = no;
                    return root;
                }
            } 
        }
        return no;
    }
};