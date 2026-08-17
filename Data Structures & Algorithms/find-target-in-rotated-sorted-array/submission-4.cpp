class Solution {
public:
    int search(vector<int>& nums, int target) {

        int lB = 0, rB = nums.size()-1;

        while(lB<rB){
            int mid = (lB+rB)/2;
            if(nums[mid]>target){
                if(nums[lB] > target && nums[mid] > nums[rB])
                    lB = mid+1;
                else
                    rB = mid;
            }
            else if(nums[mid] < target)
                if(nums[rB] < target && nums[mid] < nums[lB])
                    rB = mid;
                else
                    lB = mid+1;
            else{
                lB = mid;
                break;
            } 

            cout << mid<<endl;
        }

        if(nums[lB] == target)
            return lB;
        else
            return -1;
    }
};
