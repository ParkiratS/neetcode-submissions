class Solution {
public:

    void see(int num, vector<vector<int>>& nodeMap, vector<bool>& seen) {
        seen[num] = true;

        for (int neighbor : nodeMap[num]) {
            if (!seen[neighbor])
                see(neighbor, nodeMap, seen);
        }
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        int ans = 0;

        vector<vector<int>> nodeMap(n);
        vector<bool> seen(n, false);

        for (const auto& p : edges) {
            nodeMap[p[0]].push_back(p[1]);
            nodeMap[p[1]].push_back(p[0]);
        }

        for (int i = 0; i < n; i++) {
            if (!seen[i]) {
                ans++;
                see(i, nodeMap, seen);
            }
        }

        return ans;
    }
};