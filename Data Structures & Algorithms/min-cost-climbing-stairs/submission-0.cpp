class Solution {
public:
    vector<int> dp;

    void traverse(vector<int>& cost, int index){
        if(index == dp.size())
            return;

        dp[index] = min(dp[index-1] + cost[index-1], dp[index-2] + cost[index-2]);
        traverse(cost, index+1);
    }

    int minCostClimbingStairs(vector<int>& cost) {
        dp = vector<int>(cost.size()+1, 0);
        traverse(cost, 2);
        return dp[dp.size()-1];
    }
};
