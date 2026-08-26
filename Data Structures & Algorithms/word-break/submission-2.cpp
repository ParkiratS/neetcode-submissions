class Solution {
public:

    vector<int> memo;

    bool traverse(const string& s, const unordered_set<string>& dict, int& m_size, int l){
        if(l == s.size())
            return true;
        if(memo[l] != -1)
            return memo[l];
        int r = l;
        string temp = "";
        while(r-l+1 <= m_size && r<s.size()){
            temp += s[r];
            if(dict.find(temp) != dict.end() && traverse(s, dict, m_size, r+1)){
                memo[l] = 1;
                return true;
            }
            r++;
        }
        memo[l] = 0;
        return false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        memo = vector<int>(s.size(), -1);
        int m_size = 0;
        unordered_set<string> dict;

        for(const string& st: wordDict){
            m_size = max((int)st.size(), m_size);
            dict.insert(st);
        }

        return traverse(s, dict, m_size, 0);
        
        
    }
};
