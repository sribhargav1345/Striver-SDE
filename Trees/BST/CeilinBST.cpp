int findCeil(Node* root, int input) {
    if (root == NULL) return -1;
    
    int mini = INT_MAX;
    while(root)
    {
        if(root -> data >= input)
        {
            mini = min(mini,root -> data);
            root = root -> left;
        }
        else root = root -> right;
    }
    if(mini == INT_MAX) return -1;
    return mini;
}

// Floor
class Solution{

public:
    int floor(Node* root, int x) {
        if (root == NULL) return -1;
    
        int maxi = INT_MIN;
        while(root)
        {
            if(root -> data <= x)
            {
                maxi = max(maxi,root -> data);
                root = root -> right;
            }
            else root = root -> left;
        }
        if(maxi == INT_MIN) return -1;
        return maxi;
    }
};