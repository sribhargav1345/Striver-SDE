class Solution{
    public:
    //Function to check whether all nodes of a tree have the value 
    //equal to the sum of their child nodes.
    int isSumProperty(Node *root)
    {
        if(root == NULL){
            return true;
        }
        
        if(root -> left && root -> right) {
            return isSumProperty(root -> left) && isSumProperty(root -> right) && (root -> data == root -> left -> data + root -> right -> data);
        }
        else if(root -> left){
            return isSumProperty(root -> left) && (root -> data == root -> left -> data);
        }
        else if(root -> right){
            return isSumProperty(root -> right) && (root -> data == root -> right -> data);
        }
        
        return true;
    }
};