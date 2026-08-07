class Solution {
public:
    int myAtoi(string s) {
        long long num = 0;
        int sign = 1, n = s.length(), i = 0;

        // skip leading empty spaces
        while (i < n && s[i] == ' ') {
            i++;
        }

        // Check if we've reached the end
        if (i == n) {
            return 0;
        }

        // check for starting sign
        if (s[i] == '-') {
            sign = -1;
            i++;
        } else if (s[i] == '+') {
            i++;
        }

        while (i < n && isdigit(s[i])) {
            num = (num * 10) + (s[i] - '0');
            if (sign * num <= INT_MIN) {
                return INT_MIN;
            }
            if (sign * num >= INT_MAX) {
                return INT_MAX;
            }

            i++;
        }
        return static_cast<int>(sign * num);
    }
};