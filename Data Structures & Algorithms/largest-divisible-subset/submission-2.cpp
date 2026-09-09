class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> dp(nums.size(), 0);
        vector<int> prev(nums.size(), -1);
        vector<int> ans;
        int max_count = 0, max_i = 0;

        for(int i{1}; i<nums.size(); i++){
            for(int j = i-1; j>=0; j--){
                if(nums[i]%nums[j] == 0)
                    if(dp[j]+1 > dp[i]){
                        dp[i] = max(dp[j]+1, dp[i]);
                        prev[i] = j;
                    }
            }
            if(dp[i] > max_count){
                max_count = dp[i];
                max_i = i;
            }
        }


        while(max_i>=0){
            ans.push_back(nums[max_i]);
            max_i = prev[max_i];
        }

        return ans;

    }
};