class Solution {
public:
    vector<vector<int>> dp;

    void traverse(string& text1, string& text2, int i, int j) {
        if (i == text1.size())
            return;

        if (j == text2.size()) {
            traverse(text1, text2, i + 1, 0);
            return;
        }

        if (text1[i] == text2[j]) {
            if (i == 0 || j == 0)
                dp[i][j] = 1;
            else
                dp[i][j] = dp[i - 1][j - 1] + 1;
        }
        else {
            if (i == 0 && j == 0)
                dp[i][j] = 0;

            else if (i == 0)
                dp[i][j] = dp[i][j - 1];

            else if (j == 0)
                dp[i][j] = dp[i - 1][j];
                
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }

        traverse(text1, text2, i, j + 1);
    }

    int longestCommonSubsequence(string text1, string text2) {
        dp = vector<vector<int>>(text1.size(), vector<int>(text2.size(), 0));
        traverse(text1, text2, 0, 0);
        return dp[text1.size()-1][text2.size()-1];
    }
};
