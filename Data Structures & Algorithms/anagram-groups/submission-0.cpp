#include <unordered_map>

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, int> res;
        int index = 0;

        for(int i = 0; i < strs.size(); i++){
            string s = strs.at(i);
            sort(s.begin(), s.end());

            if(res.find(s) != res.end())
                ans[res.find(s)->second].push_back(strs.at(i));

            else{
                ans.push_back(vector<string>());
                ans[index].push_back(strs.at(i));
                res.insert({s, index});
                index++;
            }
        }
        return ans;
    }
    
};
