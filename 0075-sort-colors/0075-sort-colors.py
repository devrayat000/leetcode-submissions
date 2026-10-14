class Solution:
    def sortColors(self, nums: list[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        counts = {0: 0, 1: 0, 2: 0}
        for n in nums:
            counts[n] += 1
        it = 0
        for i in range(len(nums)):
            while counts[it] < 1 and it < 3:
                it += 1
            counts[it] -= 1
            nums[i] = it
        return nums