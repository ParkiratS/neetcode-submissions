class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(), nums.end(), 0);

        if(sum%k != 0)
            return false;

        vector<int> sums(k, 0);
        int target = sum/k;

        sort(nums.rbegin(), nums.rend());

        return traverse(nums, sums, target, 0);
        
        
    }

    bool traverse(vector<int>& nums, vector<int>& sums, int& target, int index){
        if (index == nums.size())
            return true;

        unordered_set<int> seen;

        for (int i = 0; i < sums.size(); i++) {
            if (sums[i] + nums[index] > target)
                continue;

            if (seen.count(sums[i]))
                continue;

            seen.insert(sums[i]);
            sums[i] += nums[index];

            if (traverse(nums, sums, target, index + 1))
                return true;

            sums[i] -= nums[index];
            if (sums[i] == 0)
                break;
        }

        return false;
    }


};