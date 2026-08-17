class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        for(int i = 0; i<nums.size(); i++){
            if(i!=0 && nums[i] == nums[i-1]) continue;

            int l = i+1, r = nums.size()-1;
            while(l<r){
                int current_sum = nums.at(i) + nums.at(l) + nums.at(r);
                if(current_sum == 0){
                    ans.push_back({nums.at(i), nums.at(l), nums.at(r)});
                    l++;
                    r--;
                    while (l < r && nums[l] == nums[l - 1]) {
                        l++;
                    }
                }

                else if(current_sum < 0)
                    l++;
                
                else
                    r--;
            }
        }
           
        return ans;
        
    }
};
