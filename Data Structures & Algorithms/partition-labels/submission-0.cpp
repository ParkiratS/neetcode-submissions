class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> e(26);
        vector<int> ans;

        for(int i{0}; i<s.size(); i++){
            const char& c = s[i];
            e[c-'a'] = i;
        }

        int l = 0, r = 0;
        for(int i{0}; i<s.size(); i++){
            const char& c = s[i];
            if(i > r){
                ans.push_back(r-l+1);
                l = i;
                r = i;
            }

            if(e[c-'a'] > r){
                r = e[c-'a']; 
            }
        }
        
        ans.push_back(r-l+1);
        return ans;
        
    }
};
