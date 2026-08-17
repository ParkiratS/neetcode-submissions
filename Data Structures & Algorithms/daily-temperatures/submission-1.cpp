class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size());
        stack<int> biggerTempIndex;

        for(int i = temperatures.size()-1; i>=0; i--){
            while(!biggerTempIndex.empty() && temperatures[biggerTempIndex.top()] <= temperatures[i])
                biggerTempIndex.pop();

            if(!biggerTempIndex.empty())
                res[i] = biggerTempIndex.top()-i;

            biggerTempIndex.push(i);
                 
        }


        return res;

        


        
    }
};
