//djikstra's

class Solution {
public:

    using node = pair<int, int>; //Node, distance
    struct ComparePairGreater {
        bool operator()(const node& lhs, const node& rhs) const {
            return lhs.second > rhs.second; 
        }
    };

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        priority_queue<node, vector<node>, ComparePairGreater> minHeap;
        unordered_set<int> seen;
        unordered_map<int, vector<pair<int, int>>> travelMap;

        for(const auto& t: times)
            travelMap[t[0]].push_back({t[1], t[2]});

        minHeap.push(node(k, 0));

        int time = 0;
        while(true){
            if(minHeap.empty())
                return -1;

            const pair<int, int> top = minHeap.top();
            minHeap.pop();
            if(seen.find(top.first) != seen.end())
                continue;
            
            n--;
            time = top.second;
            seen.insert(top.first);

            if(n == 0)
                break;
            
            for(const auto& t: travelMap[top.first]){
                if(seen.find(t.first) != seen.end())
                    continue;
                else
                    minHeap.push({t.first, time+t.second});
            }
            
        }

        return time;
    }
};
