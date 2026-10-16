class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        unordered_map<int, int> cache;
        int n = nums.size();
        vector<int> sums(n+1,0);

        // Prefix sum
        for (int i = 0; i < n; i++) {
            sums[i+1] = sums[i] + nums[i];
        }

        // Dynamic sliding window
        int l = 0, r = 1, steps = INT_MAX;
        while (l <= n && !(r == n && (sums[r] - sums[l]) < target)) {
            int tmp = sums[r] - sums[l];
            if (tmp < target) {
                r++;
            } else {
                steps = min(steps, r - l);
                l++;
            }
        }
        return steps == INT_MAX ? 0 : steps;
    }
};