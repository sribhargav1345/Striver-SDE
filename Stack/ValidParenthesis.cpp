class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        stack<int> st;

        map<char,char> mp;
        mp['}'] = '{';
        mp[']'] = '[';
        mp[')'] = '(';

        for(int i=0;i<n;i++)
        {
            if(s[i] == '{' || s[i] == '(' || s[i] == '['){
                st.push(s[i]);
            }
            else 
            {
                if(!st.empty() && st.top() == mp[s[i]]){
                    st.pop();
                }
                else return false;
            }
        }
        return (st.size() == 0);
    }
};