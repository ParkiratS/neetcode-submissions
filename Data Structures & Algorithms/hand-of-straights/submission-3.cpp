class Solution {
public:

    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size() % groupSize != 0)
            return false;
        unordered_map<int, int> mapping;
        priority_queue<int, vector<int>, greater<int>> min_queue;

        for(int i:hand){
            mapping[i]++;
            min_queue.push(i);
        }


        while(!min_queue.empty()){
            int curr = min_queue.top();

            if(mapping[curr] <= 0){
                min_queue.pop();
                continue;
            }

            mapping[curr]--;

            for(int i{curr+1}; i<curr+groupSize; i++){
                if(mapping[i] == 0)
                    return false;
                mapping[i]--;
            }
            min_queue.pop();
        }
        return true;
        
    }
};
