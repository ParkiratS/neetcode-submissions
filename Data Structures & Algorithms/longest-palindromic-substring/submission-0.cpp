class Solution {
public:
    string longestPalindrome(string s) {

        string longest = "";
        int left = 0, right = 0, size = 0;

        for(int i{0}; i<s.size(); i++){
            size = 1;
            int l = i-1, r = i+1;
            while(l>=0 && r<=s.size()-1 && s[l] == s[r]){
                size+=2;
                l--;
                r++;
            }

            if(size > longest.size())
                longest = s.substr(l+1,  r - l - 1);
            
            l = i-1, r = i, size = 0;
            while(l>=0 && r<=s.size()-1 && s[l] == s[r]){
                size+=2;
                l--;
                r++;
            }

            if(size > longest.size())
                longest = s.substr(l+1,  r - l - 1);

        }

        return longest;


        
    }
};
