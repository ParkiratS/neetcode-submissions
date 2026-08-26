class Solution {
public:
    vector<int> dp;

    void traverse(const vector<int>& nums, int index){
        if(index == nums.size())
            return;

        if(dp[index] == -1){
            traverse(nums, index+1);
            return;
        }

        

        int i{1};
        while(index + i <  nums.size() && i <= nums[index]){
            if(dp[index + i] == -1)
                dp[index + i] = dp[index] + 1;
            else
                dp[index + i] = min(dp[index + i], dp[index]+1);
            
            i++;
        }

        traverse(nums, index+1);
    }

    int jump(vector<int>& nums) {
        dp = vector<int>(nums.size(), -1);
        dp[0] = 0;
        traverse(nums, 0);
        return dp[nums.size()-1];
    }
};
