class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), 0));

        for(int r{0}; r<grid.size(); r++){
            for(int c{0}; c<grid[r].size(); c++){
                if(r == 0 && c == 0)
                    dp[0][0] = grid[0][0];

                else if(r == 0)
                    dp[0][c] = dp[0][c-1] + grid[0][c];

                else if(c == 0)
                    dp[r][0] = dp[r-1][0] + grid[r][0];

                else
                    dp[r][c] = min(dp[r-1][c], dp[r][c-1]) + grid[r][c];

            }
        }

        return dp[grid.size()-1][grid[0].size()-1];
        
    }
};