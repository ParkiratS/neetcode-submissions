class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> curr;

        sort(candidates.begin(), candidates.end());

        dfs(candidates, ans, curr, target, 0, 0);

        return ans;
    }

    void dfs(vector<int>& candidates, vector<vector<int>>& ans, vector<int> curr, int target, int sum, int index){

        if(sum == target){
            ans.push_back(curr);
            return;
        }
        else if(sum > target)
            return;
        
        else if(index == candidates.size())
            return;
        
        else{
            int i = index + 1;
            for(i;i<candidates.size(); i++){
                if(candidates[i]!=candidates[index])
                    break;
            }
            curr.push_back(candidates[index]);
            dfs(candidates, ans, curr, target, sum+candidates[index], index+1);
            curr.pop_back();
            dfs(candidates, ans, curr, target, sum, i);
        }
    }
};
