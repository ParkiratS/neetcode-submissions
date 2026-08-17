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


        string temp_num = "";   
        for(int i = 0; i<s.size(); i++){
            
            if(s.at(i)=='#'){
                int len = stoi(temp_num);
                ans.push_back(s.substr(i+1, len));
                i+=len;
                temp_num = "";
            }
            else
                temp_num+=s.at(i);

        }

        return ans;

    }
};
