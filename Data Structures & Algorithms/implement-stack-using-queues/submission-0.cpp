class MyStack {
public:
    int t;
    int size;
    queue<int> q;

    MyStack():size(0) {}
    
    void push(int x) {
        t = x;
        size++;
        q.push(x);
    }
    
    int pop() {
        size--;
        for(int i{0}; i<size; i++){
            q.push(q.front());
            t = q.front();
            q.pop();
        }

        int ans = q.front();
        q.pop();
        return ans;
    }
    
    int top() {
        return t;
    }
    
    bool empty() {
        return size == 0;
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