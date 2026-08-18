class Solution {
public:
    void permuting(vector<int>& nums, vector<vector<int>>& ans, vector<int>& curr, vector<bool>& seen) {
        if(curr.size() == nums.size()) {
            ans.push_back(curr);
            return;
        }

        for(int i = 0; i < nums.size(); i++) {
            if(seen[i])
                continue;

            curr.push_back(nums[i]);
            seen[i] = true;

            permuting(nums, ans, curr, seen);

            curr.pop_back();
            seen[i] = false;
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        vector<bool> seen(nums.size(), false);

        permuting(nums, ans, curr, seen);

        return ans;
    }
};