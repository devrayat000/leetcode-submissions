int findDuplicate(int* nums, int numsSize) {
    int slow = nums[0], fast = nums[0];
    do {
        slow = nums[slow];
        fast = nums[nums[fast]];
    } while (slow != fast);
    int back = nums[0];
    while (slow != back) {
        slow = nums[slow];
        back = nums[back];
    }
    return slow;
}