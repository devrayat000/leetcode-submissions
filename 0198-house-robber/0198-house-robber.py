class Solution(object):
    def __init__(self):
        self.mem = {}

    def rob(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        return self.rob_from(nums, 0)

    def rob_from(self, nums, i):
        if i >= len(nums):
            return 0
        
        if i not in self.mem:
            rob_current = nums[i] + self.rob_from(nums, i + 2)
            skip_current = self.rob_from(nums, i + 1)
            self.mem[i] = max(rob_current, skip_current)

        return self.mem[i]
        