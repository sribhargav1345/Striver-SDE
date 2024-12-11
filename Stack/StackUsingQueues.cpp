
// Using 2 queues, using 1 queue is below this one
class MyStack {
public:
queue<int> q1;
queue<int> q2;

    MyStack() {
    
    }
    
    void push(int x) {
        q1.push(x);
    }
    
    int pop() {
        while(q1.size()>1)
        {
            int k = q1.front();
            q2.push(k);

            q1.pop();
        }
        
        int op = q1.front();
        q1.pop();

        while(q2.size()>0)
        {
            int k = q2.front();
            q1.push(k);

            q2.pop();
        }
        return op;
    }
    
    int top() {
        while(q1.size()>1)
        {
            int k = q1.front();
            q2.push(k);

            q1.pop();
        }
        
        int op = q1.front();
        q1.pop();

        while(q2.size()>0)
        {
            int k = q2.front();
            q1.push(k);

            q2.pop();
        }
        q1.push(op);

        return op;
    }
    
    bool empty() {
        return (q1.empty());
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

 // Using single queue
 #include<bits/stdc++.h>

using namespace std;

class Stack {
  queue < int > q;
  public:
    void Push(int x) {
      int s = q.size();
      q.push(x);
      for (int i = 0; i < s; i++) {

        q.push(q.front());
        q.pop();
      }
    }
  int Pop() {
    int n = q.front();
    q.pop();
    return n;
  }
  int Top() {
    return q.front();
  }
  int Size() {
    return q.size();
  }
};

int main() {
  Stack s;
  s.Push(3);
  s.Push(2);
  s.Push(4);
  s.Push(1);
  cout << "Top of the stack: " << s.Top() << endl;
  cout << "Size of the stack before removing element: " << s.Size() << endl;
  cout << "The deleted element is: " << s.Pop() << endl;
  cout << "Top of the stack after removing element: " << s.Top() << endl;
  cout << "Size of the stack after removing element: " << s.Size();

}