#define min(a, b) ((a > b) ? b : a)
#define max(a, b) ((a < b) ? b : a)

int longestSubarray(int* nums, int numsSize) {
    int len = min(numsSize, 2), maxLen = len;
    for (int i = 2; i < numsSize; i++) {
        if (nums[i] == nums[i - 1] + nums[i - 2]) {
            len++;
        } else {
            len = 2;
        }
        maxLen = max(maxLen, len);
    }
    return maxLen;
}