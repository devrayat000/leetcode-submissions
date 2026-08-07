class Solution {
public:
    int reverse(int x) {
        long long carry = 0;
        return reverse(x, carry);
    }

private:
    int reverse(int x, long long& prev) {
        if (prev > INT_MAX || prev < INT_MIN) {
            return 0;
        }
        if (x == 0) {
            return prev;
        }
        prev = (x % 10) + (prev * 10);
        // println("prev={}", prev);
        return reverse(x / 10, prev);
    }
};