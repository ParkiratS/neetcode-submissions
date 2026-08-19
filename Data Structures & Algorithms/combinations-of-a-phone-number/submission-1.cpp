class Solution {
public:
    vector<string> mapping = {
        "abc", "def", "ghi", "jkl",
        "mno", "pqrs", "tuv", "wxyz"
    };

    void traverse(const string& digits, string& curr, vector<string>& ans, int index){
        if(index == digits.size()){
            if(curr.size() > 0)
                ans.push_back(curr);
            return;
        }
        
        int num = int(digits[index] - '0');

        for(char c:mapping[num-2]){
            curr += c;
            traverse(digits, curr, ans, index + 1);
            curr.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        string curr = "";

        traverse(digits, curr, ans, 0);
        return ans;
        
    }
};
