class Solution {
public:

    vector<vector<int>> merge_sort(const vector<vector<int>>& intervals, int l, int r){
        if(l >= r)
            return {intervals[r]};

        int mid = (l + r)/2;
        vector<vector<int>> left = merge_sort(intervals, l, mid);
        vector<vector<int>> right = merge_sort(intervals, mid+1, r);
        vector<vector<int>> ans;
        ans.reserve(left.size() + right.size());

        int i = 0, j = 0;

        while(i < left.size() || j < right.size()){
            if(i == left.size()){
                ans.push_back(right[j]);
                j++;
            }
            else if(j == right.size()){
                ans.push_back(left[i]);
                i++;
            }
            else{
                if(left[i][1] <= right[j][1]){
                    ans.push_back(left[i]);
                    i++;
                }
                else{
                    ans.push_back(right[j]);
                    j++;
                }
            }
        }

        return ans;
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(),
            [](const vector<int>& a, const vector<int>& b) {
                return a[1] < b[1];
            });


        int m = INT_MIN, ans = 0;
        for(const auto& s:intervals){
            if(s[0]>=m)
                m = s[1];
            else
                ans++;
        }

        return ans;
    }
};
