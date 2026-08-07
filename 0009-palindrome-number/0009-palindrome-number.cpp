class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        if (x < 10) {
            return true;
        }
        string xstr = to_string(x);
        string ystr = xstr;
        std::reverse(ystr.begin(), ystr.end());
        return xstr == ystr;
    }
};