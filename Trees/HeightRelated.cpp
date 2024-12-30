// Height of tree
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;
        return max(maxDepth(root -> left),maxDepth(root -> right)) + 1;
    }
};

// Balanced Binary Tree or Not -> Brute
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

// Not Brute
class Solution {
public: 
    int checkHeight(TreeNode* root) {
        if (root == NULL) return 0;

        int lh = checkHeight(root->left);
        int rh = checkHeight(root->right);
        
        if (lh == -1 || rh == -1 || abs(lh - rh) > 1) {
            return -1; 
        }
        
        return max(lh,rh) + 1; 
    }

    bool isBalanced(TreeNode* root) {
        return checkHeight(root) != -1;
    }
};

// Diameter of Tree
class Solution {
public:
    int findMax(TreeNode* root,int& maxi){
        if(root == NULL){
            return 0;
        }

        int lh = findMax(root -> left,maxi);
        int rh = findMax(root -> right,maxi);

        maxi = max(maxi,lh+rh);

        return (1 + max(lh,rh));
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int maxi = 0;
        findMax(root, maxi);

        return maxi;
    }
};

// Max Path Sum

class Solution {
public:
    int maxPathDown(TreeNode* root,int& maxi){
        if(root == NULL) return 0;

        int lp = max(0,maxPathDown(root -> left, maxi));
        int rp = max(0,maxPathDown(root -> right, maxi));

        maxi = max(maxi, lp+rp+ root -> val);

        return root -> val + max(lp,rp);
    }

    int maxPathSum(TreeNode* root) {

        int maxi = INT_MIN;
        maxPathDown(root, maxi);

        return maxi;
    }
};