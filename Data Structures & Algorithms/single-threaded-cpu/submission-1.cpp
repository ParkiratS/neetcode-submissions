class Solution {
public:
    struct Task{
        int start;
        int duration;
        int index;

        Task() = default;

        Task(int s, int d, int i):start(s), duration(d), index(i){}

        bool operator<(const Task& other) const {
            if(duration == other.duration)
                return start > other.start;

            return duration > other.duration;
        }

    };



    vector<int> getOrder(vector<vector<int>>& tasks) {
        vector<vector<int>> mod = tasks;
        priority_queue<Task> minHeap;
        vector<int> ans;

        for(int i{0}; i<mod.size(); i++)
            mod[i].push_back(i);

        sort(mod.begin(), mod.end());

        int i = 0, currentTime = 0;
        while(i<mod.size() || !minHeap.empty()){
            Task temp;
            if(minHeap.empty()){
                temp = Task(mod[i][0], mod[i][1], mod[i][2]);
                i++;
            }

            else{
                temp = minHeap.top();
                minHeap.pop();
            }

            currentTime = max(currentTime, temp.start) + temp.duration;
            ans.push_back(temp.index);

            for(;i<mod.size(); i++){
                if(mod[i][0] <= currentTime)
                    minHeap.push(Task(mod[i][0], mod[i][1], mod[i][2]));
                else
                    break;
            }

        }

        return ans;
        
    }
};