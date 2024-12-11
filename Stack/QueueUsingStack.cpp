class MyQueue {
public:
stack<int> st1;
stack<int> st2;

    MyQueue() {
        
    }
    
    void push(int x) {
        st1.push(x);
    }
    
    int pop() {
        while(st1.size()>1)
        {
            int k = st1.top();
            st2.push(k);

            st1.pop();
        }
        
        int op = st1.top();
        st1.pop();

        while(st2.size()>0)
        {
            int k = st2.top();
            st1.push(k);

            st2.pop();
        }
        return op;
    }
    
    int peek() {
        while(st1.size()>1)
        {
            int k = st1.top();
            st2.push(k);

            st1.pop();
        }
        
        int op = st1.top();
        // st1.pop();

        // st1.push(op);
        while(st2.size()>0)
        {
            int k = st2.top();
            st1.push(k);

            st2.pop();
        }

        return op;
    }
    
    bool empty() {
        return (st1.empty());
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */