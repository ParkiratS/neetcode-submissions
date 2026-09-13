class Solution {
public:

    void traverse(int& n, int& k, vector<vector<int>>& ans, vector<int>& curr, int i){
        if(curr.size() == k){
            ans.push_back(curr);
            return;
        }

        

        for(int j{i}; j<=n; j++){
            curr.push_back(j);
            traverse(n, k, ans, curr, j+1);
            curr.pop_back();
        }

    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> curr;


        traverse(n, k, ans, curr, 1);
        return ans;
    }
};