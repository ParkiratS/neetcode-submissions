class Solution {
public:
    
    void see(int num, unordered_map<int, vector<int>>& nodeMap, unordered_set<int>& seen){
        if(seen.find(num) != seen.end())
            return;

        seen.insert(num);

        for(int i : nodeMap[num]){
            if(seen.find(i) == seen.end())
                see(i, nodeMap, seen);
        }
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        int ans = 0;
        unordered_map<int, vector<int>> nodeMap;
        unordered_set<int> seen;

        for(auto& p:edges){

            if(nodeMap.find(p[0]) == nodeMap.end())
                nodeMap[p[0]] = {};
            
            if(nodeMap.find(p[1]) == nodeMap.end())
                nodeMap[p[1]] = {};

            nodeMap[p[0]].push_back(p[1]);
            nodeMap[p[1]].push_back(p[0]);
        }

        for(int i{0}; i<n; i++){
            if(seen.find(i) == seen.end())
                ans++;
            
            see(i, nodeMap, seen);
        }
        return ans;
    }
};
