class Solution {
public:

    bool dfs(unordered_set<int>& seen, unordered_map<int, vector<int>>& mapping, int prev, int curr){
        if(seen.find(curr) != seen.end())
            return false;

        seen.insert(curr);
        for(const int& e : mapping[curr]){
            if(e != prev && !dfs(seen, mapping, curr, e))
                return false;
                
        }

        return true;

    }

    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size() != n - 1)
            return false;
        unordered_set<int> seen;
        unordered_map<int, vector<int>> mapping;


        for(const auto& e : edges){
            if(mapping.find(e[0]) == mapping.end())
                mapping[e[0]] = {};
            if(mapping.find(e[1]) == mapping.end())
                mapping[e[1]] = {};
            mapping[e[0]].push_back(e[1]);
            mapping[e[1]].push_back(e[0]);
        }

        return (dfs(seen, mapping, -1, 0) && seen.size() == n);


    }
};
