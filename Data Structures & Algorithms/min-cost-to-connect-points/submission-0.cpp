class Solution {
public:
    
    struct Path{
        int cost;
        int destination;

        bool operator<(const Path& other) const {
            return cost > other.cost;
        }
    };


    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<priority_queue<Path>> minHeap(points.size());
        vector<int> seen(points.size(), 0);
        int seen_count = 1, ans = 0;

        for(int i{0}; i<points.size(); i++){
            for(int j{0}; j<points.size(); j++)
                minHeap[i].push(Path(abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]), j));
        }

        seen[0] = 1;

        while(seen_count<points.size()){
            int lowest = INT_MAX, index;
            for(int i{0}; i<points.size(); i++){
                if(seen[i]){
                    while(!minHeap[i].empty() && seen[minHeap[i].top().destination])
                        minHeap[i].pop();

                    if(minHeap[i].top().cost < lowest){
                        lowest = minHeap[i].top().cost;
                        index = minHeap[i].top().destination;
                    }
                }
            }

            seen_count++;
            seen[index] = 1;
            ans+=lowest;
        }

        return ans;
        
    }
};
