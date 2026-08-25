class Solution {
public:
    void traverse(const vector<int>& nums, vector<int>& dp, int index){
        if(index == nums.size())
            return;
        
        if(index == 0)
            dp[0] = nums[0];
        
        else if(index == 1)
            dp[1] = max(dp[0], nums[1]);
        
        else
            dp[index] = max(dp[index - 1], dp[index - 2] + nums[index]);

        traverse(nums, dp, index+1);
        

    }

    int rob(vector<int>& nums) {
        vector<int> dp(nums.size());

        traverse(nums, dp, 0);
        return dp[dp.size()-1];
    }
};
