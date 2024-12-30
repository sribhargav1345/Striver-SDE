Node* buildTreep(vector<int>& postorder,int poststart,int postend,vector<int>& inorder,int instart,int inend,map<int,int>& mp){
        if(poststart > postend || instart > inend){
            return NULL;
        }

        Node* root = new Node(postorder[postend]);

        int inRoot = mp[root -> data];
        int left = inRoot - instart;

        root -> left = buildTreep(postorder, poststart,poststart+left-1, inorder, instart, inRoot-1,mp);
        root -> right = buildTreep(postorder, poststart+left,postend-1, inorder, inRoot+1, inend,mp);

        return root;
    }

    Node* buildTree(vector<int>& postorder, vector<int>& inorder) {
        map<int,int> mp;
        int n = postorder.size();

        for(int i=0;i<n;i++)
        {
            mp[inorder[i]] = i;
        }

        Node* root = buildTreep(postorder,0,n-1,inorder,0,n-1,mp);
        return root;
    }