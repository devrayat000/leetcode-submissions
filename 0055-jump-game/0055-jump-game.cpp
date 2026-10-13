class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int goal = n - 1;
        for (int i = goal - 1; i > -1; i--) {
            if (nums[i] >= goal - i) {
                goal = i;
            }
        }
        return goal == 0;
    }
};
