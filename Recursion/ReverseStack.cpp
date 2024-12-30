class Solution{
public:
    void insert_at_bottom(stack<int>& st,int itr){
        if(st.size() == 0){
            st.push(itr);
        }
        
        else
        {
            auto it = st.top();
            st.pop();
            
            insert_at_bottom(st,itr);
            
            st.push(it);   
        }
    }
    
    void Reverse(stack<int> &st){
        if(st.size() > 0){
            int itr = st.top();
            st.pop();
            
            Reverse(st);
            
            insert_at_bottom(st,itr);
        }
    }
};