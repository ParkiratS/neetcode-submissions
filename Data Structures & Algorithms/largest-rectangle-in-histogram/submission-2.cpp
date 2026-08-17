class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> preSmallestNumIndexStack;
        stack<int> postSmallestNumIndexStack;

        vector<int> preSmallestNumIndex(n);
        vector<int> postSmallestNumIndex(n);

        // Pre (nearest smaller to left)
        for(int i = 0; i < n; i++) {
            while(!preSmallestNumIndexStack.empty() && heights[preSmallestNumIndexStack.top()] >= heights[i]) {
                preSmallestNumIndexStack.pop();
            }

            if(preSmallestNumIndexStack.empty()) 
                preSmallestNumIndex[i] = 0;      // left boundary is start
            else 
                preSmallestNumIndex[i] = preSmallestNumIndexStack.top() + 1;

            preSmallestNumIndexStack.push(i);
        }

        // Post (nearest smaller to right)
        for(int i = n - 1; i >= 0; i--) {
            while(!postSmallestNumIndexStack.empty() && heights[postSmallestNumIndexStack.top()] >= heights[i]) {
                postSmallestNumIndexStack.pop();
            }

            if(postSmallestNumIndexStack.empty()) 
                postSmallestNumIndex[i] = n - 1;   // right boundary is end
            else 
                postSmallestNumIndex[i] = postSmallestNumIndexStack.top() - 1;

            postSmallestNumIndexStack.push(i);
        }

        int max_area = 0;

        for(int i = 0; i < n; i++) {
            int temp_area = heights[i] * (postSmallestNumIndex[i] - preSmallestNumIndex[i] + 1);
            max_area = max(max_area, temp_area);
        }

        return max_area;
    }
};
