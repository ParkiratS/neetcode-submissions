class Solution {
public:
    vector<vector<char>> mapping = {{'a','b','c'}, {'d','e','f'}, {'g','h','i'}, {'j','k','l'}, {'m','n','o'}, {'p','q','r','s'}, {'t','u','v'}, {'w','x','y','z'}};

    void traverse(string& digits, string& curr, vector<string>& ans, int index){
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
