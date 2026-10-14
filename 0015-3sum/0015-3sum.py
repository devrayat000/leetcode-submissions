class Solution:
    def threeSum(self, nums: list[int]) -> list[list[int]]:
        n = len(nums)
        nums.sort()
        res = []
        for i in range(0, n - 2):
            if i > 0 and nums[i] == nums[i-1]:
                continue
            l, r = i+1, n-1
            target = -nums[i]
            while l < r:
                s_um = nums[l] + nums[r]
                if s_um == target:
                    res.append([nums[i], nums[l], nums[r]])
                    while l < r and nums[l] == nums[l+1]:
                        l += 1
                    while l < r and nums[r] == nums[r-1]:
                        r -= 1
                    l += 1
                    r -= 1
                elif s_um < target:
                    l += 1
                else:
                    r -= 1
        return res