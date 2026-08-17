class MinStack {
public:
        int size;
        stack<int> minStack;
        vector<int> numVector;
    MinStack() {
        size = 0;
    }
    
    void push(int val) {
        numVector.push_back(val);
        size++;
        if(minStack.empty() || minStack.top() >= val)
            minStack.push(val);
        
    }
    
    void pop() {
        if(size == 0)
            return;
        
        if(numVector[size-1] == minStack.top())
            minStack.pop();

        numVector.pop_back(); 
        size--;       
    }
    
    int top() {
        return numVector[size-1];
    }
    
    int getMin() {
        return minStack.top();
    }
};
