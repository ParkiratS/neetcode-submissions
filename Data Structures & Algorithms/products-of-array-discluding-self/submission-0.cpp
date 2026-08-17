class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans;
        int num_zeros = 0;
        int product = 1;
        

        for(int i = 0; i<nums.size(); i++){
            if(nums.at(i) == 0)
                num_zeros++;

            else
                product*=nums.at(i);
        }

        for(int i = 0; i<nums.size(); i++){
            if(nums.at(i) == 0 && num_zeros > 1)
                ans.push_back(0);
            
            else if (nums.at(i) == 0 && num_zeros == 1)
                ans.push_back(product);
            
            else if(num_zeros>=1)
                ans.push_back(0);
            
            else
                ans.push_back(product/nums.at(i));
        }

        return ans;
    }
};
