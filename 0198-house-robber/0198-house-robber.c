#define max(a, b) ((a > b) ? a : b)

int rob(int* nums, int numsSize) {
    int prev = 0, curr = 0;
    for (int i = 0; i < numsSize; i++) {
        int tmp = max(curr, prev + nums[i]);
        prev = curr;
        curr = tmp;
    }
    return curr;
}