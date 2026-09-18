class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        unordered_set<string> folders;
        vector<string> ans;

        sort(folder.begin(), folder.end());

        for(string& s:folder){
            if(ans.size() == 0)
                ans.push_back(s);
            else{
                string parent = ans.back() + '/';
                if(s.substr(0, parent.size()) != parent)
                    ans.push_back(s);
            }
            
        }


        return ans;
        
    }
};