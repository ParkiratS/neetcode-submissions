class Solution {
public:

    bool isPalindrome(string& s, int l, int r){
        while(l<=r){
            if(s[l] != s[r])
                return false;
            
            l++;
            r--;
        }

        return true;
    }

    void traverse(string& s, vector<vector<string>>& ans, vector<string>& curr, int l){
        if(l>=s.size())
            ans.push_back(curr);


        for(int i{l}; i<s.size(); i++){
            if(isPalindrome(s, l, i)){
                curr.push_back(s.substr(l,i - l + 1));
                traverse(s, ans, curr, i+1);
                curr.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> curr;

        traverse(s, ans, curr, 0);
        return ans;
        
    }
};
