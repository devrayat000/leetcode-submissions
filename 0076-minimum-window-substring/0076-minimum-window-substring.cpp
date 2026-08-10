class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty() || s.length() < t.length())
            return "";

        vector<int> seen(128, 0);
        vector<int> window(128, 0);
        int need = 0;

        for (const char& c : t) {
            if (seen[c] == 0) {
                need++;
            }
            seen[c]++;
        }

        int have = 0;
        int startIdx = -1;
        int resLen = INT_MAX;
        int l = 0, r = 0;

        for (int r = 0; r < s.length(); r++) {
            char c = s[r];
            window[c]++;

            if (seen[c] > 0 && window[c] == seen[c]) {
                have++;
            }

            while (have == need) {
                if ((r - l + 1) < resLen) {
                    resLen = r - l + 1;
                    startIdx = l;
                }
                window[s[l]]--;
                if (seen[s[l]] > 0 && window[s[l]] < seen[s[l]]) {
                    have--;
                }
                l++;
            }
        }

        return resLen == INT_MAX ? "" : s.substr(startIdx, resLen);
    }
};