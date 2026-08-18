class Solution {
public:
    void traverse(vector<int>& coins, vector<int>& ans, int num){
        if(num == ans.size()-1)
            return;

        if(ans[num] != -1){
            cout<<num<<" "<<ans[num]<<endl;
            for(int c:coins){
                if(num + c <= ans.size()-1){
                    if(ans[num+c] != -1)
                        ans[num + c] = min(ans[num]+1, ans[num+c]);
                    else
                        ans[num+c] = ans[num] + 1;
                }
            }
        }

        traverse(coins, ans, num+1);
    }

    int coinChange(vector<int>& coins, int amount) {
        vector<int> ans(amount+1, -1);
        ans[0] = 0;

        traverse(coins, ans, 0);
        return ans[amount];
    }
};
