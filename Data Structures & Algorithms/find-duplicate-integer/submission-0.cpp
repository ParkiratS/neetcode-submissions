class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        for(int i = 0; i<nums.size(); i++){
            int temp = nums[i];
            if(temp > nums.size())
                temp -= nums.size();
            
            if(nums[temp-1] > nums.size())
                return temp;
            else
                nums[temp-1]+=nums.size();
        }
        
    }
};
