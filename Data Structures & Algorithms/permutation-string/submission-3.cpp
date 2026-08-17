class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int s1Chars[26] = {};
        int s2Chars[26] = {};

        for(char c : s1)
            s1Chars[c-'a']++;

        int l = 0;
        for(int i = 0; i<=s2.size(); i++){

            bool found = true;
            for(int j = 0; j<26; j++){
                if(s1Chars[j] != s2Chars[j]){
                    found = false;
                    break;
                }
            }

            if(found)
                return true;
            else if(i == s2.size())
                break;

            s2Chars[s2[i]-'a']++;

            if(s2Chars[s2[i]-'a'] > s1Chars[s2[i]-'a'] || i-l+1 > s1.size()){
                s2Chars[s2[l]-'a']--;
                l++;
            }
        }

        return false;

    }
};
