class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {

        stack<int> preSmallestNumIndexStack;
        stack<int> postSmallestNumIndexStack;

        vector<int> preSmallestNumIndex(heights.size());
        vector<int> postSmallestNumIndex(heights.size());


        for(int i = 0; i<heights.size(); i++){
            while(!preSmallestNumIndexStack.empty() && heights[preSmallestNumIndexStack.top()] >= heights[i])
                preSmallestNumIndexStack.pop();

            if(preSmallestNumIndexStack.empty())
                preSmallestNumIndex[i] = 0;
            else
                preSmallestNumIndex[i] = preSmallestNumIndexStack.top() + 1;

            preSmallestNumIndexStack.push(i);
        }


        for(int i = heights.size()-1; i>=0; i--){
            while(!postSmallestNumIndexStack.empty() && heights[postSmallestNumIndexStack.top()] >= heights[i])
                postSmallestNumIndexStack.pop();

            if(postSmallestNumIndexStack.empty())
                postSmallestNumIndex[i] = heights.size()-1;
            else
                postSmallestNumIndex[i] = postSmallestNumIndexStack.top() - 1;

            postSmallestNumIndexStack.push(i);
        }

        int max_area = 0;

        for(int i = 0; i<heights.size(); i++){
            int temp_area = heights[i]*((postSmallestNumIndex[i] - preSmallestNumIndex[i])+1);
            max_area = max(max_area, temp_area);
        }

        return max_area;
        
    }
};
