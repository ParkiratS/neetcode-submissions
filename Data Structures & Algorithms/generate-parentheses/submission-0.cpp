class Solution {
public:


    stack<string> parenthesisGen(stack<string> strings, stack<int> Obraces, stack<int> Cbraces, int n){
        
        if(!strings.empty() && strings.top().size() == 2*n)
            return strings;

        if(strings.empty()){
            strings.push("(");
            Obraces.push(1);
            Cbraces.push(0);
            return parenthesisGen(strings, Obraces, Cbraces, n);
        }        

        else{
            stack<string> tempS;
            stack<int> tempO, tempC;

            while(!strings.empty()){
                string tempString = strings.top();
                int tempOpens = Obraces.top();
                int tempClosed = Cbraces.top();

                Obraces.pop();
                Cbraces.pop();
                strings.pop();

                if(tempOpens > tempClosed){
                    tempS.push(tempString + ")");
                    tempO.push(tempOpens);
                    tempC.push(tempClosed+1);
                }

                if(tempOpens < n){
                    tempS.push(tempString+"(");
                    tempO.push(tempOpens+1);
                    tempC.push(tempClosed);
                }
            }

            return parenthesisGen(tempS, tempO, tempC, n);
        }
        
    }


    vector<string> generateParenthesis(int n) {
        vector<string> ans;

        stack<string> tempS;
        stack<int> tempO, tempC;


        stack<string> ansStack = parenthesisGen(tempS, tempO, tempC, n);

        while(!ansStack.empty()){
            ans.push_back(ansStack.top());
            ansStack.pop();
        }

        return ans;
    }

};
