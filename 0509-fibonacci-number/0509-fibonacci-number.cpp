class Solution {
private:
    int fibDp(int n, vector<int>& cache) {
        if (n == 0 || n == 1)
            return n;
        if (cache[n] != -1)
            return cache[n];
        return cache[n] = fibDp(n - 1, cache) + fibDp(n - 2, cache);
    }

public:
    int fib(int n) {
        vector<int> cache(n + 1, -1);
        return fibDp(n, cache);
    }
};