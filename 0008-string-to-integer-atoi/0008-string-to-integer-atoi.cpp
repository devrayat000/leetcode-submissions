class Solution {
public:
    int myAtoi(string s) {
        long long num = 0;
        int sign = 1;
        bool started = false;
        for (const char& c : s) {
            if (sign * num <= INT_MIN) {
                return INT_MIN;
            }
            if (sign * num >= INT_MAX) {
                return INT_MAX;
            }

            if (c == ' ' && !started) {
                continue;
            } else if (!started && (c == '-' || c == '+')) {
                started = true;
                sign = c == '-' ? -1 : 1;
            } else if (c >= '0' && c <= '9') {
                started = true;
                num = (num * 10) + (c - '0');
            } else {
                break;
            }
            // println("num={}", num);
        }
        if (sign * num <= INT_MIN) {
            return INT_MIN;
        }
        if (sign * num >= INT_MAX) {
            return INT_MAX;
        }
        return static_cast<int>(sign * num);
    }
};