class Solution {
public:
    vector<vector<int>> mergeSort(vector<vector<int>>& trips, int l, int r){
        if(l>=r)
            return {trips[r]};

        int mid = (l+r)/2;
        vector<vector<int>> left = mergeSort(trips, l, mid);
        vector<vector<int>> right = mergeSort(trips, mid+1, r);
        vector<vector<int>> ans;

        int i = 0, j = 0;

        while(i<left.size() || j<right.size()){
            if(i == left.size()){
                ans.push_back(right[j]);
                j++;
            }
            else if(j == right.size()){
                ans.push_back(left[i]);
                i++;
            }
            else{
                if(left[i][1] < right[j][1]){
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

    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int end = trips[0][2];
        int count = 0;

        for(const vector<int>& trip:trips){
            if(trip[2] > end)
                end = trip[2];
        }

        vector<int> times(end + 1, 0);

        for(const vector<int>& trip:trips){
            times[trip[1]]+=trip[0];
            times[trip[2]]-=trip[0];
        }

        for(int& i:times){
            count+=i;
            if(count > capacity)
                return false;
        }

        return true;



    }
};