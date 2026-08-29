class Solution {
public:

    void traverse(const vector<int>& nums, vector<vector<int>>& ans, vector<int>& curr, int index){
        if(index == nums.size()){
            ans.push_back(curr);
            return;
        }

        int s = 1, i = index+1;
        curr.push_back(nums[index]);

        for(; i<nums.size(); i++){
            if(nums[i] != nums[i-1])
                break;
            
            curr.push_back(nums[i]);
            s++;
        }

        while(s>0){
            traverse(nums, ans, curr, i);
            curr.pop_back();
            s--;
        }
        traverse(nums, ans, curr, i);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> curr;

        traverse(nums, ans, curr, 0);
        return ans;


    }
};
