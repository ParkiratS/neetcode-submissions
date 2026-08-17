class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> letters_seen;
        int max_length = 0;
        int current_length = 0;

        for(int i = 0; i<s.size(); i++){
            if(letters_seen.find(s[i]) != letters_seen.end() && letters_seen[s[i]] >= i-current_length){
                if(current_length > max_length)
                    max_length = current_length;
                current_length = i-letters_seen[s[i]]-1;
            }

                        
            current_length++;
            cout<<current_length<<endl;
            letters_seen[s[i]] = i;
        }
        
        return max(max_length, current_length);
        
    }
};
