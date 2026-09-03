class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = INT_MIN, temp1 = 1, temp2 = 1;

        for(int i{0}; i<nums.size(); i++){
            int temp = temp1*nums[i];
            temp1 = max(max(nums[i]*temp1, nums[i]*temp2), nums[i]);
            temp2 = min(min(temp, nums[i]*temp2), nums[i]);

            ans = max(ans, temp1);
        }

        return ans;
        
    }
};
