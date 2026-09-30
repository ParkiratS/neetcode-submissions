class Solution {
public:

    int traverse(vector<vector<int>>& dp, vector<int>& stones, int& target, int& total, int index, int s){
        if(index == stones.size() || s >= target)
            return abs(s-(total-s));

        else if(dp[index][s] != -1)
            return dp[index][s];

        else{
            dp[index][s] = min(traverse(dp, stones, target, total, index+1, s), 
            traverse(dp, stones, target, total, index+1, s+stones[index]));
        }
        return dp[index][s];
    }

    int lastStoneWeightII(vector<int>& stones) {
        int total = accumulate(stones.begin(), stones.end(),0);
        int target = total/2;

        vector<vector<int>> dp(stones.size(), vector<int>(target+1, -1));
        return traverse(dp, stones, target, total, 0, 0);

    }
};