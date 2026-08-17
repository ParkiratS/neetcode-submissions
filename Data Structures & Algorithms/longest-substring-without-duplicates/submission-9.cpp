class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> character_map;
        int l=0, res=0;

        for(int i = 0; i<s.size(); i++){
            while(character_map.find(s[i]) != character_map.end()){
                character_map.erase(s[l]);
                l++;
            }

            res = max(res, i-l+1);
            character_map.insert(s[i]);

        }

        return res;
    }
};
