class Solution {
public:
    void traverse(const vector<int>& prices, vector<int>& dp, vector<int>& hold, int& index){
        if(index == prices.size())
            return;

        if(index == 0){
            hold[0] = -prices[0];
            dp[0] = 0;
        }

        else if(index == 1){
            hold[1] = max(hold[0], -prices[1]);
            dp[1] = max(0, prices[1]-prices[0]);
        }

        else{
            hold[index] = max(hold[index-1], dp[index-2] - prices[index]);
            dp[index] = max(dp[index-1], hold[index-1] + prices[index]);
        }
        index++;
        traverse(prices, dp, hold, index);
    }

    int maxProfit(vector<int>& prices) {
        if(prices.size() <= 1)
            return 0;
        vector<int> dp(prices.size(), 0);
        vector<int> hold(prices.size(), 0);
        int index = 0;

        traverse(prices, dp, hold, index);

        return max(dp[dp.size()-1], hold[hold.size()-1]);
    }
};
