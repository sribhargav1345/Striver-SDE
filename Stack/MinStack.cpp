class MinStack {
private:
    stack<int> s1;
    stack<int> s2;
public:
    void push(int x) {
	    s1.push(x);
	    if (s2.empty() || x <= getMin())  s2.push(x);	    
    }
    void pop() {
	    if (s1.top() == getMin())  s2.pop();
	    s1.pop();
    }
    int top() {
	    return s1.top();
    }
    int getMin() {
	    return s2.top();
    }
};

// Using single stack
class MinStack {
    stack<long long> st;
    long long mini;

    public:
        MinStack() {
            while (st.empty() == false) st.pop();
            mini = INT_MAX;
        }

    void push(int value){
        long long val = Long.valuevalue;
        if (st.empty()) {
            mini = val;
            st.push(val);
        } 
        else 
        {
            if(val<mini){
                st.push(2*val - mini);
                mini = val;
            } 
            else{
                st.push(val);
            }
        }
    }

    void pop() 
    {
        if(st.empty()) return;

        long long el = st.top();
        st.pop();

        if(el<mini){
            mini = 2*mini-el;
        }
    }

    int top() {
        if (st.empty()) return -1;

        long long el = st.top();
        if (el < mini) return mini;
        return el;
    }

    int getMin() {
        return mini;
    }
};