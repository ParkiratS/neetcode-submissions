class Solution {
public:

    void permuting(vector<int>& nums, vector<vector<int>>& ans, vector<int>& curr, unordered_set<int>& seen, int index){
        if(index >= nums.size() || index < 0 || seen.find(nums[index]) != seen.end() )
            return;

        

        curr.push_back(nums[index]);
        seen.insert(nums[index]);

        if(curr.size() == nums.size()){
            ans.push_back(curr);
            curr.pop_back();
            seen.erase(nums[index]);
            return;
        }

        for(int i{index+1}; i<nums.size(); i++)
            permuting(nums, ans, curr, seen, i);

        for(int i{index-1}; i<nums.size(); i--)
            permuting(nums, ans, curr, seen, i);
        
        curr.pop_back();
        seen.erase(nums[index]);
        if(curr.size() == 0)
            permuting(nums, ans, curr, seen, index + 1);
    }

    vector<vector<int>> permute(vector<int>& nums) {
        unordered_set<int> seen;
        vector<vector<int>> ans;
        vector<int> curr;

        permuting(nums, ans, curr, seen, 0);
        return ans;
    }
};
