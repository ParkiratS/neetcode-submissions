#include <unordered_map>

class Solution {
public:

    bool isAnagram(string s, string t) {
        unordered_map<char,int> chars_exist;

        if(s.size() != t.size())
            return false;

        for(int i = 0; i<s.size(); i++){
            if(chars_exist.find(s.at(i))!=chars_exist.end()){
                chars_exist[s.at(i)] = chars_exist[s.at(i)]+1;
            }
            else{
                chars_exist[s.at(i)] = 1;
            }

        }


        for(int i = 0; i<t.size(); i++){
            if(chars_exist.find(t.at(i))!=chars_exist.end() && chars_exist[t.at(i)] > 0){
                chars_exist[t.at(i)] = chars_exist[t.at(i)]-1;
            }
            else{
                return false;
            }
        }
        return true;
    }
};
