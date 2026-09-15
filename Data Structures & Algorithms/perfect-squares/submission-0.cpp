class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1);

        for(int i{0}; i<=n; i++)
            dp[i] = i;

        int num = 1;
        while(pow(num,2) <= n){
            for(int i{0}; i<=n; i++){
                if(i == pow(num,2))
                    dp[i] = 1;
                else{
                    if(i-pow(num,2)>0 && dp[i-pow(num,2)])
                        dp[i] = min(dp[i], dp[i-pow(num,2)]+1);
                }
            }
            num++;
        }

        return dp[n];
        
    }
};