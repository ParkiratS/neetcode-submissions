class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> charCount;
        int l = 0, res = 0;

        for (int r = 0; r < s.size(); r++) {
            charCount[s[r]]++;

            int max_count = 0;
            for (auto &p : charCount)
                max_count = max(max_count, p.second);

            int window_size = r - l + 1;
            int replacements = window_size - max_count;

            if (replacements > k) {
                charCount[s[l]]--;
                l++;
            }

            res = max(res, r - l + 1);
        }

        return res;
    }
};