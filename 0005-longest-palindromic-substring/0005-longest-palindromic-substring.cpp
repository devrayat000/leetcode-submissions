class Solution {
public:
    string longestPalindrome(string s) {
        if (s.length() < 2) {
            return s;
        }

        string longest = "";
        for (int i = 0; i < s.length() - 1; i++) {
            string odd = expandAroundCenter(s, i, i);
            string even = expandAroundCenter(s, i, i + 1);

            if (odd.length() > longest.length()) {
                longest = odd;
            }
            if (even.length() > longest.length()) {
                longest = even;
            }
        }
        return longest;
    }

private:
    string expandAroundCenter(const string& s, int left, int right) {
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            right++;
            left--;
        }
        return s.substr(left + 1, right - left - 1);
    }
};