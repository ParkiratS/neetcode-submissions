class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> existing_nums;
        priority_queue<int, vector<int>, greater<int>> nums_heap;

        for(int num : nums){
            if(existing_nums.find(num) == existing_nums.end()){
                nums_heap.push(num);
                existing_nums.insert(num);
            }
            else
                continue;
        }

        if(nums_heap.empty())
            return 0;
        
        int consec_count = 1, max_consec = 1;
        int prev_num = nums_heap.top();
        nums_heap.pop();

        while(!nums_heap.empty()){
            if(nums_heap.top() == prev_num+1)
                consec_count++;
        
            else
                consec_count = 1;

            max_consec = (consec_count > max_consec) ? consec_count : max_consec;
            prev_num = nums_heap.top();
            nums_heap.pop();
        }

        return max_consec;
        
    }
};
