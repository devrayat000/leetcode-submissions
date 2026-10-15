class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int len = min<int>(nums.size(), 2), maxLen = len;
        for (int i = 2; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1] + nums[i - 2]) {
                len++;
            } else {
                len = 2;
            }
            maxLen = max(maxLen, len);
        }
        return maxLen;
    }
};