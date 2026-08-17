class Solution {
public:

    void traverse(vector<int>& nums, vector<bool>& traversed, int index){
        if(index < 0 || index >= nums.size() || traversed[index])
            return;
        
        traversed[index] = true;

        for(int i{1}; i<=nums[index]; i++){
            traverse(nums, traversed, index+i);
            traverse(nums, traversed, index-i);
        }
    }

    bool canJump(vector<int>& nums) {
        vector<bool> traversed(nums.size(), false);

        traverse(nums, traversed, 0);
        return traversed[traversed.size()-1];
        
    }
};
