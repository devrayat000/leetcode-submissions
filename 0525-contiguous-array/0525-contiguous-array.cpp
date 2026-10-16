class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        nums[0] = nums[0] == 0 ? -1 : 1;
        for (int i = 1; i < n; i++) {
            nums[i] = nums[i - 1] + (nums[i] == 0 ? -1 : 1);
        }

        unordered_map<int, int> cache;
        int len = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                len = max(len, i + 1);
            } else {
                if (cache.contains(nums[i])) {
                    len = max(len, i - cache[nums[i]]);
                    cache[nums[i]] = min(cache[nums[i]], i);
                } else {
                    cache[nums[i]] = i;
                }
                // print("{}|{}|{},", i, nums[i], cache[nums[i]]);
            }
        }
        return len;
    }
};