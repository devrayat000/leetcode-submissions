class Solution {
public:
    bool isPalindrome(string s) {
        string cut;
        for (char c : s) {
            if (isalnum(c)) {
                cut += tolower(c);
            }
        }
        int l = 0, r = cut.length() - 1;
        while (l < r) {
            if (cut[l] != cut[r])
                return false;
            l++;
            r--;
        }
        return true;
    }
};
