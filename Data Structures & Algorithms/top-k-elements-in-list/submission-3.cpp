#include<unordered_map>
#include<map>

class Solution {
public:
    struct number_count{
        int number;
        int count;

        number_count(int number, int count):number(0),count(0) { //Remember initialization rules!!
            this->number = number;
            this->count = count;
        }

        bool operator<(const number_count& other) const { //Remember how to override operators!!
            return this->count<other.count;
        }
    };

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> num_count;
        vector<int> res;

        for(int num : nums){
            if(num_count.find(num) == num_count.end())
                num_count[num] = 1;
            else
                num_count[num]++;
        }
        
        priority_queue<number_count> heap;
        for(auto num_count_pair : num_count){
            heap.push(number_count(num_count_pair.first, num_count_pair.second));
        }

        for(int i = 0; i<k; i++){
            if(heap.empty())
                break;
            number_count temp = heap.top();
            res.push_back(temp.number);
            heap.pop();
        }

        return res;
    }
};
