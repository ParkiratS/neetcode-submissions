class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total_cost = 0, total_gas = 0;

        for(int i{0}; i<gas.size(); i++){
            total_cost += cost[i];
            total_gas += gas[i];
        }

        if(total_cost>total_gas)
            return -1;
        
        int index = -1, temp = -1;

        for(int i{0}; i<gas.size(); i++){
            int diff = gas[i] - cost[i];
            if(diff < 0 && temp + diff < 0){
                index = -1;
                temp = -1;
            }
            else if(diff < 0 && temp + diff >= 0)
                temp+=diff;

            else if(diff >= 0 && temp < 0){
                index = i;
                temp = diff;
            }
            else
                temp+=diff;
            
        }

        return index;
        
    }
};
