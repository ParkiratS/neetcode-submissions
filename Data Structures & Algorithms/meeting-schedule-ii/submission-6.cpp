/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {

public:

    struct comp{
        bool operator()(const Interval& curr, const Interval& other) const {
            return curr.start < other.start;
        }
    };

    int minMeetingRooms(vector<Interval>& intervals) {
        priority_queue<int, vector<int>, greater<int>> minHeap;
        sort(intervals.begin(), intervals.end(), comp());

        int rooms = 0, m_rooms = 0;
        for(int i{0}; i<intervals.size(); i++){
            if(!minHeap.empty()){
                while(!minHeap.empty() && intervals[i].start >= minHeap.top()){
                    minHeap.pop();
                    rooms--;
                }
            }
            minHeap.push(intervals[i].end);
            rooms++;
            m_rooms = max(rooms, m_rooms);
        }

        return m_rooms;
    }
};
