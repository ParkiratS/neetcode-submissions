class Solution {
public:

    struct carInfo{
        double duration;
        int position;

        carInfo(double duration, int position): duration(duration), position(position){}

        bool operator<(const carInfo& other) const {
            return position < other.position;
        }
    };

    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        stack<int> hoursToDest;
        priority_queue<carInfo> cars;

        for(int i = 0; i<position.size(); i++)
            cars.push(carInfo((double)(target - position[i]) / speed[i], position[i]));

        double current_time = cars.top().duration, fleets = 1;
        while(!cars.empty()){
            carInfo temp = cars.top();
            cout<<temp.duration<<endl;
            if(temp.duration>current_time){
                fleets++;
                current_time = temp.duration;
            }
            cars.pop();
        }

        return fleets;
    }
};
