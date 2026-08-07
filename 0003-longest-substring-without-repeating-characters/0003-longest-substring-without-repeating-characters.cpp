class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> seen(256, -1);
        int l = 0, r = 0, len = 0;
        while (r < s.length()) {
            if (seen[s[r]] >= l) {
                l = seen[s[r]] + 1;
            }
            seen[s[r]] = r;
            len = max(r - l + 1, len);
            r++;
        }
        return len;
    }
};
