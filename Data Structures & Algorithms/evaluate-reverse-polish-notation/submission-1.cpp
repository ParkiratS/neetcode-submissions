class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> numStack;

        int num1, num2;

        for (string s : tokens) {
            if (s == "+") {
                int num1 = numStack.top(); numStack.pop();
                int num2 = numStack.top(); numStack.pop();
                numStack.push(num2 + num1);
            } 
            else if (s == "-") {
                int num1 = numStack.top(); numStack.pop();
                int num2 = numStack.top(); numStack.pop();
                numStack.push(num2 - num1);
            } 
            else if (s == "*") {
                int num1 = numStack.top(); numStack.pop();
                int num2 = numStack.top(); numStack.pop();
                numStack.push(num2 * num1);
            } 
            else if (s == "/") {
                int num1 = numStack.top(); numStack.pop();
                int num2 = numStack.top(); numStack.pop();
                numStack.push(num2 / num1);
            } 
            else {
                numStack.push(stoi(s));
            }
        }

        return numStack.top();
        
    }
};
