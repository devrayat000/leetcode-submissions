class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size(), sum = nums[0], prev = nums[0];
        unordered_set<int> cache = {0};

        for (int i = 1; i < n; i++) {
            sum += nums[i];
            if (cache.contains(sum % k)) {
                return true;
            }
            cache.insert(prev % k);
            prev = sum;
        }
        return false;
    }
};