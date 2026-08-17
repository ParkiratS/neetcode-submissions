#include <cmath>
#include <queue>

using Item = pair<vector<int>, float>;

bool comparePoints(Item& p1, Item& p2){
    return p1.second > p2.second;
}

float dist(int& p1, int& p2){
    return std::sqrt(p1 * p1 + p2 * p2);
}

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        std::priority_queue<Item, std::vector<Item>, decltype(&comparePoints)> minHeap(&comparePoints);
        vector<vector<int>> ans;

        for(vector<int> point : points)
            minHeap.push({point, dist(point[0], point[1])});

        for(int i{0}; i<k; i++){
            ans.push_back(minHeap.top().first);
            minHeap.pop();
        }

        return ans;
        
    }
};
