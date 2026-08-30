class Solution {
public:

    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size() + s2.size() != s3.size())
            return false;
        vector<vector<bool>> dp(s1.size()+1, vector<bool>(s2.size()+1, false));
        dp[0][0] = true;
        for(int r{0}; r<=s1.size(); r++){
            for(int c{0}; c<=s2.size(); c++){
                if(!dp[r][c])
                    continue;
                
                if (r < s1.size() && s1[r] == s3[r + c])
                    dp[r + 1][c] = true;

                if (c < s2.size() && s2[c] == s3[r + c])
                    dp[r][c + 1] = true;
            }
        }

        return dp[s1.size()][s2.size()];
    }
};
