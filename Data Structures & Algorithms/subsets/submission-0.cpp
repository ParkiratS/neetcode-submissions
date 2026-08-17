class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        subsetsHelper(nums, ans);
        return ans;
            
    }

    void subsetsHelper(vector<int>& nums, vector<vector<int>>& ans){
        if(nums.empty()){
            ans.push_back({});
            return;
        }

        else{
            int ansSize = ans.size();
            int currNum = nums[nums.size()-1];
            for(int i = 0; i<ansSize; i++){
                vector<int> tempVector(ans[i]);
                tempVector.push_back(currNum);
                ans.push_back(tempVector);
            }
                
            ans.push_back({currNum});
            nums.pop_back();
        }

        subsetsHelper(nums, ans);
    }
};
