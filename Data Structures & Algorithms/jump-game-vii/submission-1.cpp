class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        vector<bool> reached(s.size(), false);
        reached[0] = true;

        for(int i{0}; i<s.size(); i++){
            if(s[i] == '0' && reached[i]){
                for(int j = i+minJump; j<=min(i+maxJump, (int)s.size()-1); j++){
                    if(s[j] == '0')
                        reached[j] = true;
                }
            }
        }

        return reached[s.size()-1];
        
    }
};