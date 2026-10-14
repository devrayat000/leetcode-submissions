class Solution {
    long long solve(const vector<vector<int>>& intervals, long long k) {
        long long ans = 0, cur = 0;
        int n = intervals.size(), j = 0;

        for (int i = 0; i < n; ++i) {
            long long l_i = intervals[i][0];
            long long r_i = intervals[i][1];
            long long c_i = intervals[i][2];
            long long window_end = l_i + k - 1;

            while (j < n && intervals[j][0] <= window_end) {
                cur += 1LL * (intervals[j][1] - intervals[j][0] + 1) *
                       intervals[j][2];
                j++;
            }

            long long excess = 0;
            if (j > i && intervals[j - 1][1] > window_end) {
                excess = 1LL * (intervals[j - 1][1] - window_end) *
                         intervals[j - 1][2];
            }

            ans = max(ans, cur - excess);
            cur -= (r_i - l_i + 1) * c_i;
        }
        return ans;
    }

public:
    long long maximumCoins(vector<vector<int>>& coins, int k) {
        sort(coins.begin(), coins.end());
        long long res1 = solve(coins, k);

        vector<vector<int>> mirrored;
        mirrored.reserve(coins.size());
        for (int i = (int)coins.size() - 1; i >= 0; --i) {
            mirrored.push_back({-coins[i][1], -coins[i][0], coins[i][2]});
        }
        long long res2 = solve(mirrored, k);

        return max(res1, res2);
    }
};