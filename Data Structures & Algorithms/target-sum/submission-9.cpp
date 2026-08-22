class Solution {
public:
    vector<vector<int>> dp;
    int totalSum;

    int traverse(vector<int>& nums, int& target, int num, int i){
        if(i == nums.size())
            return num == target;

        if(dp[i][totalSum+num] != INT_MIN)
            return dp[i][totalSum+num];

        dp[i][num+totalSum] = traverse(nums, target, num + nums[i], i+1) +  traverse(nums, target, num - nums[i], i+1);
        return dp[i][num+totalSum];
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        totalSum = accumulate(nums.begin(), nums.end(), 0);
        dp = vector<vector<int>>(nums.size(), vector<int>(2*totalSum+1, INT_MIN));
        return traverse(nums, target, 0,0);
    }
};
