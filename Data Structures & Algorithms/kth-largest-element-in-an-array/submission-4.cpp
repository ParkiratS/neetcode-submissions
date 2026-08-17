class Solution {

public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, std::greater<int>> minHeap;
        int heapSize = 0;

        for(int i: nums){
            if(heapSize < k){
                minHeap.push(i);
                heapSize++;
            }
            
            else{
                if(minHeap.top() < i){
                    minHeap.pop();
                    minHeap.push(i);
                }
            }
        }
        
        return minHeap.top();
    }
};
