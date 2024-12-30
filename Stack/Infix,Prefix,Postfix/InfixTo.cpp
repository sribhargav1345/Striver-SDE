// Infix To Postfix
class Solution {
  public:
    int value(char c){
        if(c == '^'){
            return 3;
        }
        else if(c == '/' || c == '*'){
            return 2;
        }
        else if(c == '+' || c == '-'){
            return 1;
        }
        return 0;
    }
    
    string infixToPostfix(string& s) {
        stack<char> st;
        int n = s.size();
        
        string ans = "";
        
        for(int i=0;i<n;i++)
        {
            if(('A' <= s[i] && s[i] <= 'Z') || ('a' <= s[i] && s[i] <= 'z') || ('0' <= s[i] && s[i] <= '9'))
            {
                ans += s[i];
            }
            else if(s[i] == '(') st.push(s[i]);
            else if(s[i] == ')') 
            {
                while(st.top() != '('){
                    ans += st.top();
                    st.pop();
                }
                st.pop();
            }
            else
            {
                while(!st.empty() && value(s[i])<=value(st.top())){
                    ans += st.top();
                    st.pop();
                }
                st.push(s[i]);
            }
        }
        
        while(!st.empty())
        {
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};

// Infix to Prefix
/// Reverse the infix
/// Infix to Postfix
/// Reverse the answer