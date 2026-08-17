class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        multiset<int> orderedNums;
        vector<int> output;

        int max = nums[0];
        for(int i = 0; i<k; i++){
            if(nums[i]>max)
                max = nums[i];

            orderedNums.insert(nums[i]);
        }

        output.push_back(max);

        int l = 1, r = k;

        while(r<nums.size()){
            auto it = orderedNums.find(nums[l-1]);
            orderedNums.erase(it);

            orderedNums.insert(nums[r]);
            int max = *(orderedNums.rbegin());

            output.push_back(max);

            l++;
            r++;
        }

        return output;
    }
};
