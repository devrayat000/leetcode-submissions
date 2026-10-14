class Solution:
    def productExceptSelf(self, nums: list[int]) -> list[int]:
        total_prod = 1
        has_zero, has_prod = 0, False
        for n in nums:
            if n != 0:
                total_prod *= n
                has_prod = True
            else:
                has_zero += 1
        if not has_prod or has_zero > 1:
            return [0] * len(nums)
        ret = []
        for n in nums:
            if has_zero and n != 0:
                ret.append(0)
            elif has_zero:
                ret.append(total_prod)
            else:
                ret.append(int(total_prod / n))
        return ret