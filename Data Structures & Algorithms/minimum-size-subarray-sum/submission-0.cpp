class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {

        queue<int> q;
        int curr_sum = 0, len = 0, ans = INT_MAX;

        for(int i{0}; i<nums.size(); i++){
            curr_sum+=nums[i];
            len++;
            q.push(nums[i]);

            while(curr_sum>=target && !q.empty()){
                ans = min(ans, len);

                curr_sum-=q.front();
                q.pop();
                len--;
            }
        }

        if(ans == INT_MAX)
            return 0;
        return ans;
        
    }
};