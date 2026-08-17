#include<unordered_map>
#include<map>

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> element_map;
        map<int, vector<int>, greater<int>> count_map;
        set<int> res;


        for(int i = 0; i<nums.size(); i++){

            int item_count = 0;

            if(element_map.find(nums.at(i)) == element_map.end()){
                item_count, element_map[nums.at(i)] = 1;
            }
            else{
                element_map[nums.at(i)]++;
                item_count = element_map[nums.at(i)];
            }

            if(count_map.find(item_count) == count_map.end())
                count_map[item_count] = {nums.at(i)};
            else
                count_map[item_count].push_back(nums.at(i));
        }


        for(map<int, vector<int>>::iterator map_iterator = count_map.begin(); map_iterator != count_map.end(); map_iterator++){
            if(res.size() >= k)
                break;
            for(int j = 0; j<map_iterator->second.size(); j++){
                cout<<map_iterator->second.at(j)<<endl;
                res.insert(map_iterator->second.at(j));
                if(res.size() >= k)
                    break;
            }
        }

        return vector<int>(res.begin(),res.end());

    }
};
