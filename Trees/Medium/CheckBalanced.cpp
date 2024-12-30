class Solution {
public: 
    int maxH(TreeNode* root){
        if(root == NULL) return 0;
        return max(maxH(root -> left), maxH(root -> right)) + 1;
    }

    bool isBalanced(TreeNode* root) {

        if(root == NULL) return true;

        int lh = maxH(root -> left);
        int rh = maxH(root -> right);

        return abs(lh-rh) <= 1 && isBalanced(root -> left) && isBalanced(root -> right);
    }
};