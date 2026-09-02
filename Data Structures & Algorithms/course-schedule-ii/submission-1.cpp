class Solution {
public:

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> m(numCourses);
        vector<int> num_pres(numCourses, 0);

        for(const auto& p:prerequisites){
            m[p[1]].push_back(p[0]);
            num_pres[p[0]]++;
        }

        queue<int> src;
        int seen = 0;
        vector<int> ans;

        for(int i{0}; i<numCourses; i++){
            if(num_pres[i] == 0)
                src.push(i);
            
        }

        while(!src.empty()){
            int temp = src.front();
            src.pop();
            ans.push_back(temp);
            seen++;

            for(int& i : m[temp]){
                num_pres[i]--;
                if(num_pres[i] == 0)
                    src.push(i);
            }
        }

        if(seen == numCourses)
            return ans;

        return {};
        
        
    }
};
