class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> comb;
        backtrack(s, 0, comb, ans);

        return ans;
    }

private:
    void backtrack(const string& s, int start, vector<string>& comb,
                   vector<vector<string>>& ans) {
        if (start == s.length()) {
            ans.push_back({comb});
            return;
        }

        for (int end = start; end < s.length(); end++) {
            if (isPalindrome(s, start, end)) {
                comb.push_back(s.substr(start, end - start + 1));
                backtrack(s, end + 1, comb, ans);
                comb.pop_back();
            }
        }
    }

    bool isPalindrome(const string& s, int left, int right) {
        while (left < right) {
            if (s[left++] != s[right--]) {
                return false;
            }
        }
        return true;
    }
};