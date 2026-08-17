class Solution {
public:
    int findMin(vector<int> &nums) {
        bool smaller = false, bigger = false;
        int lB = 0, rB = nums.size()-1; 

        while(lB < rB){
            int middle = (lB+rB)/2;
            if(nums[lB] > nums[rB]){
                if(nums[middle] < nums[rB])
                    rB = middle;
                else
                    lB = middle+1;
            }

            else
                break;
        }

        return nums[lB];
    }
};
