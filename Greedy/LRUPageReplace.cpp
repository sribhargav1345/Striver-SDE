// Can be done using set and map

class Solution{
public:
    int pageFaults(int n, int capacity, int pages[]){
        map<int,int> mp;
        set<int> st;
        
        int page_fault = 0;
        
        for(int i=0;i<n;i++)
        {
            if(st.size() < capacity)
            {
                if(st.find(pages[i]) == st.end())
                {
                    st.insert(pages[i]);
                    page_fault++;
                }
                mp[pages[i]] = i;
            }
            else
            {
                if(st.find(pages[i]) == st.end())
                {
                    int lru = INT_MAX;
                    int val;
                    
                    for(auto it = st.begin(); it != st.end() ; it++)
                    {
                        if(mp[*it] <lru)
                        {
                            lru = mp[*it];
                            val = *it;
                        }
                    }
                    st.erase(val);
                    st.insert(pages[i]);
                    
                    page_fault++;
                }
                mp[pages[i]] = i;
            }
        }
        return page_fault;
    }
};