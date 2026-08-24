class Solution {
public:

    vector<vector<int>> m_sort(vector<vector<int>>& intervals, int l, int r){
        if(l >= r)
            return {intervals[r]};
        
        int mid = (l + r)/2;
        vector<vector<int>> left = m_sort(intervals, l, mid);
        vector<vector<int>> right = m_sort(intervals, mid+1, r);

        vector<vector<int>> ans(left.size()+right.size());

        int i = 0, j = 0;

        while(i<left.size() || j<right.size()){
            if(i == left.size()){
                ans[i+j] = right[j];
                j++;
            }
            else if(j == right.size()){
                ans[i+j] = left[i];
                i++;
            }
            else{
                if(left[i][0]<=right[j][0]){
                    ans[i+j] = left[i];
                    i++;
                }
                else{
                    ans[i+j] = right[j];
                    j++;
                }
            }
        }

        return ans;
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans = m_sort(intervals, 0, intervals.size()-1);
        vector<vector<int>> out;
        int l = ans[0][0], r = ans[0][1];

        for(int i{1}; i<ans.size(); i++){
            vector<int>& temp = ans[i];
            if(temp[0] <= r)
                r = max(r, temp[1]);
            else{
                out.push_back({l, r});
                l = temp[0];
                r = temp[1];
            }
        }

        out.push_back({l, r});
        return out;

        
    }
};
