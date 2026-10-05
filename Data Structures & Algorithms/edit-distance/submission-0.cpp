class Solution {
public:


    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, INT_MAX));

        dp[0][0] = 0;
        for(int i = 0; i <= word1.size(); i++)
            dp[i][0] = i;

        for(int j = 0; j <= word2.size(); j++)
            dp[0][j] = j;

        for(int r{1}; r<=word1.size(); r++){
            for(int c{1}; c<=word2.size(); c++){
                if(word1[r-1] == word2[c-1])
                    dp[r][c] = dp[r-1][c-1];
                else
                    dp[r][c] = 1 + min(dp[r-1][c], min(dp[r][c-1], dp[r-1][c-1]));
            }
        }

        return dp[word1.size()][word2.size()];
        
    }
};
