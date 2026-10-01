class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        vector<int> postHeights(heights.size(), INT_MIN);
        vector<int> ans;
        int curr_max = INT_MIN;

        for(int i = heights.size()-1; i>=0; i--){
            postHeights[i] = curr_max;
            curr_max = max(heights[i], curr_max);
        }

        for(int i{0}; i<heights.size(); i++){
            if(postHeights[i] < heights[i])
                ans.push_back(i);
        }
        
        return ans;
    }
};