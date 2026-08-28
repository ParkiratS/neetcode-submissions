class Solution {
public:

    vector<bool> seen;

    bool traverse(vector<vector<int>>& m, vector<bool>& temp, int num){
        if(m[num].size() == 0 || seen[num])
            return true;

        if(temp[num]){
            cout<<num<<endl;
            return false;
        }

        temp[num] = true; 
        for(int& i:m[num]){
            if(!traverse(m, temp, i))
                return false;
            seen[i] = true;
        }

        return true;
    }
    

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> m(numCourses+1);
        seen = vector<bool>(numCourses+1, false);

        for(const auto& p:prerequisites)
            m[p[1]].push_back(p[0]);

        for(int i{0}; i<numCourses; i++){
            vector<bool> temp(numCourses+1, false);
            if(!traverse(m, temp, i))
                return false;
        }

        return true;
    }
};
