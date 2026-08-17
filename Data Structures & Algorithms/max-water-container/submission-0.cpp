class Solution {
public:
    int maxArea(vector<int>& heights) {

        int max_area = 0;

        int l = 0, r = heights.size()-1;

        while(l<r){
            int current_area = min(heights[l], heights[r]) * (r-l);
            if(current_area > max_area)
                max_area = current_area;
            
            if(heights[l] > heights[r])
                r--;
            else
                l++;
        }

        return max_area;
        
    }
};
