class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        if (x < 10) {
            return true;
        }
        return x == reverse(x, 0);
    }

private:
    int reverse(int x) {
        // use long to track overflow
        // regular int will throw error
        long long carry = 0;
        return reverse(x, carry);
    }

    // pass value by reference to save memory
    int reverse(int x, long long prev) {
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