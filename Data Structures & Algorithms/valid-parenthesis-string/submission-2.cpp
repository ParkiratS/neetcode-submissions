class Solution {
public:
    bool checkValidString(string s) {
        stack<int> p_stack;
        stack<int> s_stack;

        for(int i{0}; i<s.size(); i++){
            char c = s[i];

            if(c =='(')
                p_stack.push(i);
            if(c == '*')
                s_stack.push(i);
            if(c == ')'){
                if(!p_stack.empty())
                    p_stack.pop();
                else if(!s_stack.empty())
                    s_stack.pop();
                else
                    return false;
            }
        }

        while(!p_stack.empty()){
            if(s_stack.empty())
                return false;
            if(p_stack.top() > s_stack.top())
                return false;
            p_stack.pop();
            s_stack.pop();
        }

        return true;
        
    }
};
