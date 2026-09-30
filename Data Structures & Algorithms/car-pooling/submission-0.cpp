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

    struct Arrival{
        int location;
        int people;

        Arrival(int l, int p): location(l), people(p){}

        bool operator<(const Arrival& other) const{
            return location > other.location;
        }
    };

    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<vector<int>> sorted = mergeSort(trips, 0, trips.size()-1);
        priority_queue<Arrival> minHeap;
        int load = 0;

        for(const vector<int>& trip:sorted){
            while(!minHeap.empty() && trip[1] >= minHeap.top().location){
                load -= minHeap.top().people;
                minHeap.pop();
            }
            if(load + trip[0] > capacity)
                return false;
            
            load += trip[0];
            minHeap.push(Arrival(trip[2], trip[0]));
        }

        return true;
    }
};