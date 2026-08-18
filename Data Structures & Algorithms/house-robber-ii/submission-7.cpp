class Solution {
public:

    int traverse(vector<int>& nums, int start, int end){
        int p1 = 0, p2 = 0, ans = 0, curr = 0;

        for(int i{start}; i<end; i++){
            curr = max(p1, p2+nums[i]);
            ans = max(ans, curr);
            p2 = p1;
            p1 = curr;
        }

        return ans;
    }

    int rob(vector<int>& nums) {
        if(nums.size() == 1)
            return nums[0];
        return max(traverse(nums, 0, nums.size()-1), traverse(nums, 1, nums.size()));

    }
};
