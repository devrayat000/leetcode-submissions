class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSub = nums[0], curr = 0;
        for (int num : nums) {
            curr = max(curr, 0) + num;
            maxSub = max(maxSub, curr);
        }
        return maxSub;
    }
};
