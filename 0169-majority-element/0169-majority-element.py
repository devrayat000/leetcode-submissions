class Solution:
    def majorityElement(self, nums: list[int]) -> int:
        counter = Counter(nums)
        return max(counter, key=counter.get)