class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        mp = defaultdict(int)
        n = len(nums)
        sums = [0] * (n + 1)

        for i in range(n):
            sums[i + 1] = nums[i] + sums[i]
        count = 0

        for i in range(n + 1):
            t = sums[i] - k
            if t in mp:
                count += mp[t]
            mp[sums[i]] += 1

        return count