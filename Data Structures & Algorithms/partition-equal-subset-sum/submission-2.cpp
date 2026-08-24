class Solution {
public:
    vector<vector<bool>> dp;
    vector<bool> visited;

    void traverse(vector<int>& nums, int index){
        if(index == nums.size())
            return;

        int num = nums[index];

        for(int i{0}; i<dp.size(); i++){
            if(visited[i])
                continue;

            if(i - num < 0)
                continue;

            if(!visited[i-num])
                continue;

            if(!dp[i-num][index]){
                vector<bool> temp = dp[i-num];
                temp[index] = true;
                dp[i] = temp;
                visited[i] = true;
            }
        }

        traverse(nums, index+1);
    }

    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int& n:nums)
            sum+=n;
        

        dp = vector<vector<bool>>(sum/2 + 1, vector<bool>(nums.size(), false));
        visited = vector<bool>(sum/2 + 1, false);
        visited[0] = true;

        traverse(nums, 0);

        for(int i{0}; i<dp.size(); i++){
            int temp = 0;
            for(int j{0}; j<nums.size(); j++){
                if(!dp[i][j])
                    temp+=nums[j];
            }

            cout<<i<<" "<<temp<<endl;

            if(temp == i)
                return true;
        }

        return false;
    }
};
