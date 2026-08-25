class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = nums[0];
        int temp = nums[0];

        for(int i{1}; i<nums.size(); i++){
            if(nums[i] > 0 && temp <= 0)
                temp = nums[i];
            else if(temp + nums[i] < 0)
                temp = nums[i];
            else{
                temp += nums[i];
            }
            ans = max(temp, ans);
        }

        return ans;


    }
};
