class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> subset;

        dfs(nums, ans, subset, 0, 0, target);

        return ans;

    }

    void dfs(vector<int>& nums, vector<vector<int>>& ans, vector<int> subset, int currSum, int index, int target){
        if(index>=nums.size()){
            if(currSum == target)
                ans.push_back(subset);
            return;
        }

        if(currSum == target){
            ans.push_back(subset);
            return;
        }

        if(currSum > target)
            return;
        
        subset.push_back(nums[index]);
        dfs(nums, ans, subset, currSum + nums[index], index, target);
        subset.pop_back();
        dfs(nums, ans, subset, currSum, index+1, target);
        

    }
};
