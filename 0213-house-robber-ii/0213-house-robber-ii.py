class Solution:
    def rob(self, nums: List[int]) -> int:

        @cache
        def rob_from(i: int, e: int) -> int:
            if len(nums) == 1:
                return nums[0]
                
            if i >= len(nums) - e:
                return 0

            rob = nums[i] + rob_from(i + 2, e)
            skip = rob_from(i + 1, e)

            return max(rob, skip)

        first = rob_from(0, 1)
        second = rob_from(1, 0)
        return max(first, second)
    
        