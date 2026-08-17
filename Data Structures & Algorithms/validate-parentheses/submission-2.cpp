class Solution {
public:
    bool isValid(string s) {
        stack<char> groupStack;


        for(char c : s){
            
            switch(c){
                case '(':
                case '[':
                case '{':
                    groupStack.push(c);
                    break;
                case ')':
                    if(groupStack.empty() || groupStack.top() != '(')
                        return false;
                    groupStack.pop();
                    break;
                case '}':
                    if(groupStack.empty() || groupStack.top() != '{')
                        return false;
                    groupStack.pop();
                    break;
                case ']':
                    if(groupStack.empty() || groupStack.top() != '[')
                        return false;
                    groupStack.pop();
                    break;
                default:
                    break;
            }
        }


        return groupStack.empty();
        
    }
};
