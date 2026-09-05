class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int ans1 = nums[0], ans2 = nums[0], curr_max = nums[0], curr_min = nums[0], total_sum = nums[0];
        int n = nums.size();

        for(int i{1}; i<nums.size(); i++){
            curr_max = max(curr_max+nums[i], nums[i]);
            curr_min = min(curr_min+nums[i], nums[i]);
            total_sum+=nums[i];
            ans1 = max(ans1, curr_max);
            ans2 = min(ans2, curr_min);

        }

        if (ans1 < 0)
            return ans1;

        return max(ans1, total_sum-ans2);
        
    }
};