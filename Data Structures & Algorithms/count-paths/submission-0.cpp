class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = 1;

        for(int r{0}; r<m; r++){
            for(int c{0}; c<n; c++){
                if(r < m-1)
                    dp[r+1][c] += dp[r][c];
                
                if(c < n-1)
                    dp[r][c+1] += dp[r][c];
            }
        }

        return dp[m-1][n-1];


    }
};
