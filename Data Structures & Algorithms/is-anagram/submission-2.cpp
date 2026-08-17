#include <unordered_set>

class Solution {
public:

    string sort(string s){
        if(s.size() <= 1)
            return s;

        string sub1 = sort(s.substr(0, s.size()/2));
        string sub2 = sort(s.substr(s.size()/2, s.size()));
        string output = "";

        int i = 0;
        int j = 0;
        while(i<sub1.size() && j < sub2.size()){
            if(sub1.at(i) >= sub2.at(j)){
                output = output+sub1.at(i);
                i++;
            }
            else{
                output = output+sub2.at(j);
                j++;
            }
        }

        if(i<sub1.size())
            output = output+sub1.substr(i, sub1.size());
        else if(j<sub2.size())
            output = output+sub2.substr(j, sub2.size());
        
        return output;
    }

    bool isAnagram(string s, string t) {

        s = sort(s);
        t = sort(t);

        if(s.size() != t.size())
            return false;

        for(int i = 0; i<s.size(); i++){
            if(s.at(i)!=t.at(i))
                return false;
        }

        return true;
    }
};
