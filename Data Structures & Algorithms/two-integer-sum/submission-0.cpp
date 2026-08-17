#include <unordered_map>

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> nums_exist;

        for(int i = 0; i<nums.size(); i++){
            if(nums_exist.find(target-nums.at(i)) != nums_exist.end()){
                return {min(i, nums_exist[target-nums.at(i)]), max(i, nums_exist[target-nums.at(i)])};
            }
            else{
                nums_exist[nums.at(i)] = i;
            }
        }
        return {};
    }
    
};
