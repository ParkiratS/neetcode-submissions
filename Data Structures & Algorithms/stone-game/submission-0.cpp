class Solution {
public:
    int traverse(vector<int>& piles, vector<vector<int>>& dp, int i, int j){
        if(i>=piles.size() || j<0 || i > j)
            return 0;

        if (dp[i][j] != INT_MIN)
            return dp[i][j];

        int takeLeft = piles[i] - traverse(piles, dp, i + 1, j);

        int takeRight = piles[j] - traverse(piles, dp, i, j - 1);

        return dp[i][j] = max(takeLeft, takeRight);


    }

    bool stoneGame(vector<int>& piles) {
        int n = piles.size();

        vector<vector<int>> dp(n,vector<int>(n, INT_MIN));

        return traverse(piles, dp, 0, n - 1) > 0;


        
    }
};