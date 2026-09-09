class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> dp(nums.size(), 0);
        vector<int> ans;
        int max_count = 0, max_i = 0;

        for(int i{1}; i<nums.size(); i++){
            for(int j = i-1; j>=0; j--){
                if(nums[i]%nums[j] == 0)
                    dp[i] = max(dp[j]+1, dp[i]);
            }
            if(dp[i] > max_count){
                max_count = dp[i];
                max_i = i;
            }
        }

        for(int& n:nums){
            if(nums[max_i] % n == 0)
                ans.push_back(n);
        }

        return ans;

    }
};