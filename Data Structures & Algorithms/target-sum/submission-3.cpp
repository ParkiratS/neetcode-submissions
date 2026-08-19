class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;

        for(int n : nums)
            sum += n;

        if(abs(target) > sum)
            return 0;

        vector<int> sums(2*sum + 1, 0);
        sums[sum] = 1;

        for(int n : nums){
            vector<int> next(2 * sum+1, 0);

            for(int i = -sum; i <= sum; i++){
                if(sums[i + sum] == 0)
                    continue;

                if(i + n <= sum)
                    next[i + n + sum] += sums[i + sum];

                if(i - n >= -sum)
                    next[i - n + sum] += sums[i + sum];
            }

            sums = move(next);
        }

        return sums[target + sum];
    }
};