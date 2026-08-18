class Solution {
public:
// 1, 2, 10, 3, 10

    void traverse(vector<int>& nums, vector<int>& n, int& ans, int index, bool first){
        if(nums.size() == 1){
            ans = nums[0];
            return;
        }
        if(index >= nums.size())
            return;
        
        if(index == nums.size()-1 && first)
            return;

        if(index == 0 || index == 1)
            n[index] = nums[index];
        
        else if(index == 2)
            n[index] = n[index-2] + nums[index];
        
        else
            n[index] = max(n[index-2], n[index-3]) + nums[index];
            

        ans = max(ans, n[index]);
        traverse(nums, n, ans, index+1, first);
    }

    int rob(vector<int>& nums) {
        vector<int> n(nums.size(), 0);
        int ans = 0;
        
        traverse(nums, n, ans, 0, true);
        fill(n.begin(), n.end(), 0); 
        traverse(nums, n, ans, 1, false);

        return ans;

    }
};
