void create_tree(node* root0, vector<int> &vec){
    //Your code goes here
    queue<node*> q;
    q.push(root0);
    
    int n = vec.size();
    int ct = 1;
    
    while(!q.empty() && ct<n)
    {
        auto itr = q.front();
        q.pop();
        
        node* l = newNode(vec[ct]);
        node* r = newNode(vec[ct+1]);
        
        itr -> left = l;
        itr -> right = r;
        
        ct += 2;
        
        q.push(l);
        q.push(r);
    }
    
}