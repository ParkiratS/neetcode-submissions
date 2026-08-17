class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        unordered_map<int, int> nums_index;
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        for(int i = 0; i<nums.size(); i++)
            nums_index[nums.at(i)] = i;

        
        for(int i = 0; i < nums.size()-2;i++){
            if(i!=0 && nums.at(i) == nums.at(i-1))
                continue;
            
            for(int j = i+1; j<nums.size()-1; j++){
                if(j!=i+1 && nums.at(j) == nums.at(j-1))
                continue;

                if(nums_index.find(-(nums.at(i)+nums.at(j))) != nums_index.end() && nums_index.find(-(nums.at(i)+nums.at(j)))->second > j)
                    ans.push_back({nums.at(i), nums.at(j), -(nums.at(i)+nums.at(j))});
            }
        }
           
        return ans;
        
    }
};
