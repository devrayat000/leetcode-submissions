class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        if (n < 2) {
            return false;
        }

        for (int i = 1; i < n; i++) {
            nums[i] = nums[i] + nums[i - 1];
        }

        unordered_set<int> cache = {0};

        for (int i = 0; i < n; i++) {
            if (i > 0 && cache.contains(nums[i] % k)) {
                return true;
            }
            if (i > 0) {
                cache.insert(nums[i - 1] % k);
            }
        }
        return false;
    }
};