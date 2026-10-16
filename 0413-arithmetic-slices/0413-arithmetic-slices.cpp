class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) {
            return 0;
        }

        int prev = nums[1] - nums[0], curr = 0;
        int i = 0, count = 0, prevIdx = 1;
        for (i = 2; i < n; i++) {
            curr = nums[i] - nums[i - 1];
            if (curr != prev) {
                count += sumConsecutive(i - prevIdx + 1);
                prev = curr;
                prevIdx = i;
            }
        }
        // println("{}, {}, {}", i, prevIdx, count);
        return count + sumConsecutive(i - prevIdx + 1);
    }

private:
    int sumConsecutive(int n) {
        if (n < 3)
            return 0;
        return (n - 2) * (n - 1) / 2;
    }
};