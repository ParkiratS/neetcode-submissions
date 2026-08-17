class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans(2);
        int first_index = 0;
        int last_index = numbers.size()-1;

        while(first_index < last_index){
            int sum = numbers.at(first_index) + numbers.at(last_index);
            if(sum == target){
                ans[0] = first_index+1;
                ans[1] = last_index+1;
                break;
            }
            else if(sum>target)
                last_index--;
            else
                first_index++;
        }

        return ans;
        
    }
};
