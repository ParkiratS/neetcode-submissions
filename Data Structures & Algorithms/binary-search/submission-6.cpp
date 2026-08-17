class Solution {
public:
    int search(vector<int>& nums, int target) {
        int index = nums.size()/2;
        int leftIndex = -1, rightIndex = nums.size();

        while(true){
            cout<<index<<endl;
            if(index == leftIndex || index == rightIndex)
                return -1;

            else if(nums[index] == target)
                return index;
            
            else if(target > nums[index]){
                leftIndex = index;
                index = (index + rightIndex)/2;
            }
            else{
                rightIndex = index;
                index = (index + leftIndex)/2;
            }

            
        }
        
    }
};
