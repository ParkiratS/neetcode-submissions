class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {

        int i1 = newInterval[0], i2 = newInterval[1];
        for(vector<int>& i:intervals){
            if((i[0] >= i1 && i[0] <= i2) || (i[1] >= i1 && i[1] <= i2)){
                i1 = min(i1, i[0]);
                i2 = max(i2, i[1]);
            }
            else if((i[0] <= i1 && i[1]>=i2) || (i[0] >= i1 && i[1] <= i2)){
                i1 = min(i1, i[0]);
                i2 = max(i2, i[1]);
            }
        }
        
        vector<vector<int>> ans;
        vector<int> temp = {i1, i2};
        bool added = false;

        for(vector<int>& i:intervals){
            if(i[0] > i2){
                if(!added){
                    ans.push_back(temp);
                    added = true;
                }
                ans.push_back(i);
            }
            else if(i[1] < i1)
                ans.push_back(i);
        }

        if(!added)
            ans.push_back(temp);

        return ans;
        
    }
};
