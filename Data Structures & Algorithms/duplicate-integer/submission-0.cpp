#include <unordered_set>

class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> nums_exist;

        for(int i = 0; i<nums.size(); i++){
            if(nums_exist.find(nums[i]) != nums_exist.end()){
                return true;
            }
            nums_exist.insert(nums[i]);
        }

        return false;
    }
};
