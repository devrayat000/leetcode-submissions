class Solution(object):
    def rob(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n = len(nums)
        if n == 1:
            return nums[0]
            
        first = self.rob_from(nums, 0, n - 1)
        second = self.rob_from(nums, 1, n)
        return max(first, second)

    def rob_from(self, nums, start, end):
        prev = curr = 0

        for i in range(start, end):
            prev, curr = curr, max(nums[i] + prev, curr)
        
        return curr
        