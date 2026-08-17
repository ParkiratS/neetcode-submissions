class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int max_profit = profit;
        int current_low_price = prices[0];

        for(int i = 0; i<prices.size(); i++){
            if(prices[i] < current_low_price){
                if(profit>max_profit)
                    max_profit = profit;
                current_low_price = prices[i];
                profit = 0;
            }

            else{
                if(prices[i] - current_low_price > profit)
                    profit = prices[i] - current_low_price;
            }
        }

        return max(profit, max_profit);
    }
};
