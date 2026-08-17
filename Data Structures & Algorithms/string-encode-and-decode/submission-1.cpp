class Solution {
public:

    string encode(vector<string>& strs) {
        string ans = "";
        for(string s:strs){
            ans+=to_string(s.size())+"#"+s;
        }
        return ans;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        int i = 0;

        while (i < s.size()) {
            string temp_num = "";

            // Accumulate number until '#'
            while (s[i] != '#') {
                temp_num += s[i];
                i++;
            }

            int len = stoi(temp_num);
            i++; // Skip '#'

            // Extract substring of length `len`
            ans.push_back(s.substr(i, len));
            i += len; // Move to next length
        }

        return ans;

    }
};
